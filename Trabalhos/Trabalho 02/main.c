#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num_caixas = MAX_CAIXAS;
    Caixa *caixas = (Caixa *)malloc(num_caixas * sizeof(Caixa));

    for (int i = 0; i < num_caixas; i++)
    {
        caixas[i].id = i + 1;
        caixas[i].estado = 1;
        caixas[i].fila = criar_fila();
    }

    int opcao;
    while (1)
    {
        printf("\n MENU \n");
        printf("1. Cadastrar um Cliente\n");
        printf("2. Atender um Cliente\n");
        printf("3. Abrir ou Fechar um Caixa\n");
        printf("4. Imprimir a Lista de Clientes em Espera\n");
        printf("5. Imprimir o Status dos Caixas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {

            Cliente *cliente = (Cliente *)malloc(sizeof(Cliente));
            printf("Nome: ");
            scanf("%s", cliente->nome);
            printf("CPF (somente números): ");
            scanf("%s", cliente->cpf);
            printf("Prioridade (1 = alta, 2 = média, 3 = baixa): ");
            scanf("%d", &cliente->prioridade);
            printf("Itens no carrinho: ");
            scanf("%d", &cliente->itens);

            int caixa_id;
            printf("Número do caixa (1 a %d): ", num_caixas);
            scanf("%d", &caixa_id);

            if (caixa_id >= 1 && caixa_id <= num_caixas && caixas[caixa_id - 1].estado == 1)
            {
                cadastrarCliente(caixas[caixa_id - 1].fila, cliente);
                printf("Cliente %s cadastrado no caixa %d\n", cliente->nome, caixa_id);
            }
            else
            {
                printf("Caixa inválido ou fechado.\n");
                free(cliente);
            }
            break;
        }

        case 2:
        {

            int caixa_id;
            printf("Número do caixa (1 a %d): ", num_caixas);
            scanf("%d", &caixa_id);

            if (caixa_id >= 1 && caixa_id <= num_caixas && caixas[caixa_id - 1].estado == 1)
            {
                Cliente *cliente = atenderCliente(caixas[caixa_id - 1].fila);
                if (cliente != NULL)
                {
                    printf("Atendendo cliente %s - CPF: %s - Prioridade: %d - Itens: %d\n",
                           cliente->nome, cliente->cpf, cliente->prioridade, cliente->itens);
                    free(cliente);
                }
                else
                {
                    printf("Nenhum cliente em espera no caixa %d.\n", caixa_id);
                }
            }
            else
            {
                printf("Caixa inválido ou fechado.\n");
            }
            break;
        }

        case 3:
        {

            int caixa_id;
            printf("Número do caixa (1 a %d): ", num_caixas);
            scanf("%d", &caixa_id);

            if (caixa_id >= 1 && caixa_id <= num_caixas)
            {
                if (caixas[caixa_id - 1].estado == 1)
                {
                    fecharCaixa(caixas, num_caixas, caixa_id);
                }
                else
                {
                    caixas[caixa_id - 1].estado = 1;
                    printf("Caixa %d foi aberto.\n", caixa_id);
                }
            }
            else
            {
                printf("Caixa inválido.\n");
            }
            break;
        }

        case 4:
        {

            imprimir_clientes_em_espera(caixas, num_caixas);
            break;
        }

        case 5:
        {

            imprimir_status_caixas(caixas, num_caixas);
            break;
        }

        case 0:
        {

            for (int i = 0; i < num_caixas; i++)
            {
                free(caixas[i].fila);
            }
            free(caixas);
            return 0;
        }

        default:
            printf("Opção inválida.\n");
            break;
        }
    }

    return 0;
}
