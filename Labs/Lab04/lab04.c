#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


//funcao 01
void freq(char *s) //usa o void pq n retorna nada, usa o * pq uma string e um ponteiro pra varios caracteres
{
    int be[128] = {0};  //inicia um novo vetor de int e torna a 0
    int i;
    for (int i = 0; s[i] != '\0'; ++i) { //loop ate o final da str
        be[s[i]]++;               //s[i] isto pega tds os caracteres da str e como caractere tem um valor numero da tabela ascii
                                  //esse valor e utilizado como indice do vetor be e esse indice e incrementado
    }
    for (int i = 0; i < 128; ++i) {  
        if (be[i] > 0) {
            printf("%d %c\n", be[i], i); //esse loop identifica qual dos indices foi incrementado e printa
        }
    }
}

//funcao 02
//função para substituir teclado por teclado ou mouse
void teclado(char frase[]) {
    char resultado[2000] = ""; //buffer para o resultado final
    int i = 0, j = 0;

    //processa a frase
    while (frase[i] != '\0') {
        //verifica se encontramos a palavra teclado
        if (strncmp(&frase[i], "teclado", 7) == 0) {
            //copia teclado ou mouse para o resultado
            strcpy(&resultado[j], "teclado ou mouse");
            j += strlen("TECLADO OU MOUSE");
            i += 7; //pula a palavra teclado na frase original
        } else {
            //copia o caractere atual para o resultado
            resultado[j] = frase[i];
            j++;
            i++;
        }
    }
    //finaliza a string de resultado
    resultado[j] = '\0';

    printf("Frase reescrita: %s\n", resultado);
    
}

//funcao 03
void estudante(char frase[]) {
    char resultado[2000] = ""; //buffer para o resultado final
    int i = 0, j = 0;

    // Processa a frase
    while (frase[i] != '\0') {
        //verifica se encontramos a palavra aluno
        if (strncmp(&frase[i], "aluno", 5) == 0) {
            //copia estudante para o resultado, usa com n pq consgue colcoar o numero de caracteres que eu quero que compare
            strcpy(&resultado[j], "estudante");
            j += strlen("estudante");
            i += 5; //pula a palavra aluno na frase original
        } 
        //verifica se encontramos a palavra escola
        else if (strncmp(&frase[i], "escola", 6) == 0) {
            //copia universidade para o resultado
            strcpy(&resultado[j], "universidade");
            j += strlen("universidade");
            i += 6; //pula a palavra escola na frase original
        } else {
            //copia o caractere atual para o resultado
            resultado[j] = frase[i];
            j++;
            i++;
        }
    }
    //finaliza a string de resultado
    resultado[j] = '\0';

    printf("Frase reescrita: %s\n", resultado);
}

//funcao 04
//ler os elementos e atribuar a matriz quando for chamada
void lerMatriz(int linhas, int colunas, int **matriz) {
    printf("Digite os elementos da matriz (%d x %d):\n", linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}
//um vetor e apenas varios ponteiros e quando passado para uma funcao deve ser passada como ponteiro
void multiplicarMatrizes(int **matriz1, int l1, int c1, int **matriz2, int l2, int c2, int **resultado) {
//inicializa a matriz resultado com zeros
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < c2; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}
//printa a matriz 
void exibirMatriz(int linhas, int colunas, int **matriz) {
    printf("Matriz resultante (%d x %d):\n", linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int num1;
    printf("Escolha entre o exercício 1, 2, 3 ou 4:\n");
    scanf("%d", &num1);
    getchar();  //limpa o buffer do '\n' deixado pelo scanf,tava skippando direto

    switch (num1) {
       
        case 1: {
        char strip[128];
        printf("Digite uma palavra: ");
        fgets(strip, 128, stdin);
        //chama a função para contar e imprimir a frequência de cada caractere na palavra
        freq(strip);
        break;
        }

        case 2: {
        char frase[1000];//str
    
        printf("Digite uma frase: ");
        fgets(frase, 1000, stdin);
  
        teclado(frase);
        break;
        }

        case 3: {
         char frase[2000];

        printf("Digite a frase: ");
        fgets(frase, sizeof(frase), stdin);

        //remove o caractere de nova linha, se presente
        frase[strcspn(frase, "\n")] = '\0';

        estudante(frase);
        break;
        }

        case 4: {
         int l1, c1, l2, c2;

    //leitura das dimensões das matrizes
    printf("Digite o número de linhas e colunas da primeira matriz:\n");
    scanf("%d %d", &l1, &c1);

    printf("Digite o número de linhas e colunas da segunda matriz:\n");
    scanf("%d %d", &l2, &c2);

    //verifica se a multiplicação é possível(se coluna 1 for diferente da linha dois, n da)
    if (c1 != l2) {
        printf("A multiplicação das matrizes não é possível.\n");
        return 1;
    }

    //aloca memória para as matrizes
    int **matriz1 = (int **)malloc(l1 * sizeof(int *));
    int **matriz2 = (int **)malloc(l2 * sizeof(int *));
    int **resultado = (int **)malloc(l1 * sizeof(int *));

    for (int i = 0; i < l1; i++) {
        matriz1[i] = (int *)malloc(c1 * sizeof(int));
        resultado[i] = (int *)malloc(c2 * sizeof(int));
    }
    for (int i = 0; i < l2; i++) {
        matriz2[i] = (int *)malloc(c2 * sizeof(int));
    }

    //leitura dos elementos das matrizes
    printf("Matriz 1:\n");
    lerMatriz(l1, c1, matriz1);
    printf("Matriz 2:\n");
    lerMatriz(l2, c2, matriz2);

    //multiplicacaoo das matrizes
    multiplicarMatrizes(matriz1, l1, c1, matriz2, l2, c2, resultado);

    //exibicao da matriz resultante
    exibirMatriz(l1, c2, resultado);

    //ibera a memória alocada
    for (int i = 0; i < l1; i++) {
        free(matriz1[i]);
        free(resultado[i]);
    }
    for (int i = 0; i < l2; i++) {
        free(matriz2[i]);
    }
    free(matriz1);
    free(matriz2);
    free(resultado);
    break;
}
    }
}
