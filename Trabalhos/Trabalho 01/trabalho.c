#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// funcao 01
int inicioX, inicioY;
bool **visitado; // matriz de visitados
//ver se a prox casa ta segura
bool seguro(int i, int j, char **matriz, int linhas, int colunas)
{
    return (i >= 0 && j >= 0 && i < linhas && j < colunas && matriz[i][j] != 'R' && !visitado[i][j]);
}
//funcao 
bool fuga_humana(char **matriz, int i, int j, int linhas, int colunas)
{
    if (!seguro(i, j, matriz, linhas, colunas))
        return false;

    if (matriz[i][j] == 'Z')
        return true;

    visitado[i][j] = true;

    if (fuga_humana(matriz, i - 1, j, linhas, colunas))
    {
        matriz[i][j] = '*';
        return true;
    }
    if (fuga_humana(matriz, i, j + 1, linhas, colunas))
    {
        matriz[i][j] = '*';
        return true;
    }
    if (fuga_humana(matriz, i + 1, j, linhas, colunas))
    {
        matriz[i][j] = '*';
        return true;
    }
    if (fuga_humana(matriz, i, j - 1, linhas, colunas))
    {
        matriz[i][j] = '*';
        return true;
    }

    visitado[i][j] = false;
    return false;
}

// funcao desafio 02
// funcao recursiva de fibonacci(calcula o enesimo termo da sequencia)
int fibonacci(int n)
{
    if (n == 1)
        return 0;
    else
    {
        if (n == 2)
            return 1;
        else
        {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }
}

// busca binaria
int busca_binaria(int *vet, int fim, int chave)
{
    int inicio = 0;
    int meio;

    while (inicio <= fim)
    {

        meio = (inicio + fim) / 2;
        if (chave == vet[meio])
        {
            return meio;
        }
        else
        {
            if (chave < vet[meio])
            {
                fim = meio - 1;
            }
            else
            {
                inicio = meio + 1;
            }
        }
    }
    return -1;
}

int busca_fibonacci(int n, int x)
{
    int *fib = (int *)malloc(n * sizeof(int));

    for (int i = 1; i <= n; i++)
    {
        fib[i - 1] = fibonacci(i);
    }

    int indice = busca_binaria(fib, n - 1, x);

    free(fib);
    return indice;
}

// funcao desafio 03
void verificar_palindromo(char frase[])
{
    char fraseContrario[100];
    int i, j = 0, k;

    // colocar todas as letras minusculas
    for (int z = 0; z < strlen(frase); z++)
    {
        frase[z] = tolower(frase[z]);
    }

    // tirar tudo que n e letra
    for (int n = 0; n < strlen(frase); n++)
    {
        if (isalpha(frase[n]))
        {
            frase[j++] = frase[n];
        }
    }
    frase[j] = '\0';

    // inverter a frase sem espaços e caracteres nao alfabetico
    for (i = 0, k = j - 1; k >= 0; i++, k--)
    {
        fraseContrario[i] = frase[k];
    }
    fraseContrario[i] = '\0';

    // aqui o strcmp compara a frase toda com ela invertida, se for igual, vai ser igual a 0 e printar TRUE, se nao vai printar FALSE
    if (strcmp(frase, fraseContrario) == 0)
    {
        printf("TRUE");
    }
    else
    {
        printf("FALSE");
    }
}

int main()
{
    int num1;
    printf("Escolha entre os desafios 1, 2 ou 3 :\n");
    scanf("%d", &num1);
    getchar(); // limpa o buffer do '\n' deixado pelo scanf,tava skippando direto

    switch (num1)
    {

    case 1:
    {
        char **matriz;
        int i, j;
        int linhas, colunas;
        FILE *arq;

        arq = fopen("labirinto.txt", "r");
        if (!arq)
        {
            printf("Erro na abertura do arquivo.");
            exit(1);
        }

        //lendo as linhas e colunas do arquivo
        fscanf(arq, "%d %d", &linhas, &colunas);
        printf("%d %d\n", linhas, colunas);

        //alocando memoria
        matriz = (char **)malloc(linhas * sizeof(char *));
        for (i = 0; i < linhas; i++)
        {
            matriz[i] = (char *)malloc(colunas * sizeof(char));
        }

        visitado = (bool **)malloc(linhas * sizeof(bool *));
        for (int i = 0; i < linhas; i++)
        {
            visitado[i] = (bool *)malloc(colunas * sizeof(bool));
            memset(visitado[i], false, linhas * sizeof(bool));
        }

        fgetc(arq);
        for (i = 0; i < linhas; i++)
        {
            for (j = 0; j < colunas; j++)
            {
                matriz[i][j] = fgetc(arq);
            }
            fgetc(arq); // consume the newline character
        }
        fclose(arq);

        //achar a posicao H
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                if (matriz[i][j] == 'H')
                {
                    inicioX = i;
                    inicioY = j;
                }
            }
        }
        

        if (fuga_humana(matriz, inicioX, inicioY, linhas, colunas))
        {
            printf("Caminho encontrado\n");
        }
        else
        {
            printf("Caminho nao encontrado\n");
        }

        // printando a matriz inteira
        for (i = 0; i < linhas; i++)
        {
            for (j = 0; j < colunas; j++)
            {
                if (i == inicioX && j == inicioY)
                    printf("| %c ", 'H');
                else
                    printf("| %c ", matriz[i][j]);
            }
            printf("\n");
        }

        // liberando a memoria alocada
        for (i = 0; i < linhas; i++)
        {
            free(matriz[i]);
        }
        free(matriz);

        return 0;
    }

    case 2:
    {
        int n, x;

        printf("Digite o numero de termos da sequencia de Fibonacci: ");
        scanf("%d", &n);
        printf("Digite um numero para verificarmos se esta nesta sequencia de Fibonacci: ");
        scanf("%d", &x);

        int indice = busca_fibonacci(n, x);

        if (indice != -1)
        {
            printf(" O termo %d esta na posicao: %d\n", x, indice);
        }
        else
        {
            printf("Indice do item %d é : -1\n", x);
        }
        return 0;
    }

    case 3:
    {
        // declarar variaveis
        char frase[100];
        // pedir o usuario pra digitar uma frase(e usar o fgets pq pega dps do espaco)
        printf("Digite uma frase ou palavra, para verficar se e um palindromo:");
        fgets(frase, sizeof(frase), stdin);

        // substitui o caractere de nova linha(\n) por um terminador nulo \0, removendo assim o caractere de nova linha da string
        frase[strcspn(frase, "\n")] = '\0';

        verificar_palindromo(frase);

        return 0;
    }
    default:
        printf("Desafio inválido.\n");
        return 0;
    }
}