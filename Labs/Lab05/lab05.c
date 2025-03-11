#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#define TAM 100

int main() {

    int opcao;

    printf("Escolha entre o exercio 1 e 2:\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    getchar(); //para consumir o newline deixado pelo scanf

    switch (opcao) {
        case 1: {
            FILE *fp;
            char str[30], nome[TAM], linha[TAM];
            int i, x = 1;

            //le um nome para o arquivo a ser aberto
            printf("\n\nEntre com um nome para o arquivo:\n");
            fgets(str, 80, stdin);
            str[strlen(str) - 1] = '\0';
            if (!(fp = fopen(str, "w"))) {
                printf("Não é possível abrir o arquivo!\n");
                exit(1);
            }

            printf("Digite o nome dos %d estudantes: \n", TAM);
            for (i = 0; i < TAM; i++) {
                printf("Aluno %d. O nome do estudante e: ", i + 1);
                fgets(nome, 100, stdin);
                nome[strlen(nome) - 1] = '\0';
                if (strcmp(nome, "sair") == 0) {
                    break;
                }
                fputs(nome, fp);
                fputs("\n", fp);
            }
            fclose(fp);

            fp = fopen(str, "r");
            printf("Lendo o arquivo:\n");

            while (fgets(linha, TAM, fp) != NULL) {
                for (int i = 0; i < strlen(linha); i++) {
                    linha[i] = toupper(linha[i]);
                }
                printf("\tNome %d: %s", x, linha);
                x++;
            }
            fclose(fp);
            break;
        }
        case 2: {
            FILE *fp;
            char str[30], frase[TAM], linha[20][100], palavra[50];
            int i, num = 0;

            //le um nome para o arquivo a ser aberto
            printf("\n\nEntre com um nome para o arquivo:\n");
            fgets(str, 80, stdin);
            str[strlen(str) - 1] = '\0';
            if (!(fp = fopen(str, "w"))) {
                printf("Não e possivel abrir o arquivo!\n");
                exit(1);
            }

            printf("Escreva frases, de ate 100 caracteres (Digite 'fim' para encerrar) \n");
            for (i = 0; i < 20; i++) {
                printf("Frase %d: ", i + 1);
                fgets(frase, 100, stdin);
                frase[strlen(frase) - 1] = '\0';
                if (strcmp(frase, "fim") == 0) {
                    break;
                }
                fputs(frase, fp);
                fputs("\n", fp);
            }
            fclose(fp);

            fp = fopen(str, "r");
            printf("Lendo o arquivo:\n");

            //armazenando na matriz
            for (int i = 0; i < 20; i++) {
                if (fgets(linha[i], TAM, fp) != NULL) {
                    linha[i][strlen(linha[i]) - 1] = '\0'; //chega no final da linha, diminui 1 e coloca 0
                    num++;
                } else {
                    break;
                }
            }
            fclose(fp);

            //mostrando a matriz
            for (int i = 0; i < num; i++) {
                printf("Linha %d: %s\n", i + 1, linha[i]);
            }

            //buscando a palavra
            printf("Digite uma palavra para buscar em alguma linha: ");
            scanf("%s", palavra);
            printf("Linhas que tem a palavra '%s':\n", palavra);
            for (int i = 0; i < num; i++) {
                if (strstr(linha[i], palavra) != NULL) {
                    printf("Linha %d: %s\n", i + 1, linha[i]);
                }
            }
            break;
        }
        default:
            printf("Opcao invalida!\n");
            break;
    }

    return 0;
}
