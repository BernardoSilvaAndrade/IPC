#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *arq;
    int linhas, colunas;
    int i, j;
    int **matriz;

    arq = fopen("matriz.txt", "r");
    if (!arq)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }

    // lendo as linhas e colunas do arquivo
    fscanf(arq, "%d %d", &linhas, &colunas);
    printf("%d   %d\n", linhas, colunas);

    // alocano memoria
    matriz = (int **)malloc(linhas * sizeof(int *));
    for (i = 0; i < linhas; i++)
    {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }

    // lendo a matriz inteira
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            fscanf(arq, "%d", &matriz[i][j]);
        }
    }

    // printando a matriz
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    int colunast = linhas;
    int linhast = colunas;
    int **matriztransposta;

    matriztransposta = (int **)malloc(linhast * sizeof(int *));
    for (i = 0; i < linhast; i++)
    {
        matriztransposta[i] = (int *)malloc(colunast * sizeof(int));
    }

    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            matriztransposta[j][i] = matriz[i][j];
        }
    }

    printf("A sua matriz transposta e:\n");
    for (i = 0; i < linhast; i++)
    {
        for (j = 0; j < colunast; j++)
        {
            printf("%d ", matriztransposta[i][j]);
        }
        printf("\n");
    }
    fclose(arq);

    // escrevendo no arquivo
    FILE *arquivo;
    arquivo = fopen("transposta.txt", "w");

    if (!arquivo)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }

    // printando no arquivo
    for (i = 0; i < linhast; i++)
    {
        for (j = 0; j < colunast; j++)
        {
            fprintf(arquivo, "%d ", matriztransposta[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    // liberando memoria
    for (i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    for (i = 0; i < colunast; i++)
    {
        free(matriztransposta[i]);
    }
    free(matriztransposta);
    fclose(arquivo);

    return 0;
}