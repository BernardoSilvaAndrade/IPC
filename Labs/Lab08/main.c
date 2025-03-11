#include <stdio.h>
#include <string.h>
#include "fila.h"

int main()
{
    Fila *f = criar_fila(); // Cria uma fila vazia
    int opcao;
    Pessoa dado;

    do
    {
        printf("Escolha uma opção:\n");
        printf("1 - Inserir na fila\n");
        printf("2 - Remover da fila\n");
        printf("3 - Imprimir a fila\n");
        printf("0 - Sair\n");
        scanf(" %d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            printf("Digite o CPF: ");
            scanf("%d", &dado.cpf);
            getchar();

            printf("Digite o seu Nome: ");
            fgets(dado.nome, 50, stdin);
            dado.nome[strcspn(dado.nome, "\n")] = '\0';

            printf("Digite a prioridade (1 se for prioritário e 0 se não): ");
            scanf("%d", &dado.prioridade);
            getchar();

            enfileirar(f, dado);
            break;

        case 2:
            dado = desenfileirar(f);
            if (dado.cpf != -1)
            {
                printf("Dado removido: CPF %d, Nome: %s\n", dado.cpf, dado.nome);
            }
            break;

        case 3:
            mostrar_fila(f);
            break;

        case 0:
            break;

        default:
            printf("Opção inválida.\n");
            break;
        }
    } while (opcao != 0);

    liberar_fila(f); // Libera a memória da fila
}
