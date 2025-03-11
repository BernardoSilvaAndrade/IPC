#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main()
{
    Pilha minhaPilha;
    Doc doc;
    criarPilha(&minhaPilha);

    int opcao, numAutores;
    char buffer[100];

    while (1)
    {
        printf("\n1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Mostrar topo\n");
        printf("4 - Verificar se está vazia\n");
        printf("5 - Salvar pilha\n");
        printf("6 - Carregar pilha\n");
        printf("7 - Sair\n");
        printf("Opção? ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            printf("Identificação do Documento: ");
            scanf("%d", &doc.id);
            getchar();
            printf("Título: ");
            fgets(doc.titulo, 100, stdin);
            doc.titulo[strcspn(doc.titulo, "\n")] = '\0';

            printf("Número de autores: ");
            scanf("%d", &numAutores);
            getchar();

            doc.autores = (Autor *)malloc(numAutores * sizeof(Autor));
            doc.num_autores = numAutores;

            for (int i = 0; i < numAutores; i++)
            {
                printf("ID do autor: ");
                scanf("%d", &doc.autores[i].id);
                getchar();
                printf("Nome do autor: ");
                fgets(doc.autores[i].nome, 100, stdin);
                doc.autores[i].nome[strcspn(doc.autores[i].nome, "\n")] = '\0';
            }

            empilhar(&minhaPilha, doc);
            break;

        case 2:
            desempilhar(&minhaPilha);
            break;

        case 3:
            mostrarTopo(&minhaPilha);
            break;

        case 4:
            if (estaVazia(&minhaPilha))
            {
                printf("Pilha vazia\n");
            }
            else
            {
                printf("Pilha não está vazia\n");
            }
            break;

        case 5:
            salvarArquivo(&minhaPilha, "pilha.bin");
            break;

        case 6:
            carregarArquivo(&minhaPilha, "pilha.bin");
            break;

        case 7:
            exit(0);
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    }

    return 0;
}
