#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FilaPrioridade *criar_fila()
{
    FilaPrioridade *fila = (FilaPrioridade *)malloc(sizeof(FilaPrioridade));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

void cadastrarCliente(FilaPrioridade *fila, Cliente *novoCliente)
{
    novoCliente->prox = NULL;

    if (fila->inicio == NULL)
    {
        fila->inicio = novoCliente;
        fila->fim = novoCliente;
    }
    else
    {
        Cliente *atual = fila->inicio;
        Cliente *anterior = NULL;

        while (atual != NULL && atual->prioridade <= novoCliente->prioridade)
        {
            anterior = atual;
            atual = atual->prox;
        }

        if (anterior == NULL)
        {
            novoCliente->prox = fila->inicio;
            fila->inicio = novoCliente;
        }
        else
        {
            anterior->prox = novoCliente;
            novoCliente->prox = atual;
        }

        if (novoCliente->prox == NULL)
        {
            fila->fim = novoCliente;
        }
    }
}

Cliente *atenderCliente(FilaPrioridade *fila)
{
    if (fila->inicio == NULL)
    {
        return NULL;
    }
    else
    {
        Cliente *cliente = fila->inicio;
        fila->inicio = fila->inicio->prox;
        if (fila->inicio == NULL)
        {
            fila->fim = NULL;
        }
        return cliente;
    }
}

void fecharCaixa(Caixa *caixas, int num_caixas, int caixa_id)
{
    if (caixas[caixa_id - 1].estado == 0)
    {
        printf("Caixa %d já está fechado.\n", caixa_id);
        return;
    }

    Cliente *cliente = caixas[caixa_id - 1].fila->inicio;

    if (cliente != NULL)
    {
        printf("Realocando clientes do caixa %d...\n", caixa_id);

        while (cliente != NULL)
        {
            Cliente *proximoCliente = cliente->prox;

            int caixaDestino = -1;
            for (int i = 0; i < num_caixas; i++)
            {
                if (caixas[i].estado == 1 && i != (caixa_id - 1))
                {
                    caixaDestino = i;
                    break;
                }
            }

            if (caixaDestino != -1)
            {
                cliente->prox = NULL;
                cadastrarCliente(caixas[caixaDestino].fila, cliente);
                printf("Cliente %s realocado para o caixa %d\n", cliente->nome, caixas[caixaDestino].id);
            }
            else
            {
                printf("Nenhum caixa aberto disponível para realocar os clientes.\n");
                break;
            }

            cliente = proximoCliente;
        }
    }

    caixas[caixa_id - 1].estado = 0;
    caixas[caixa_id - 1].fila->inicio = NULL;
    caixas[caixa_id - 1].fila->fim = NULL;

    printf("Caixa %d foi fechado.\n", caixa_id);
}

void imprimir_clientes_em_espera(Caixa *caixas, int num_caixas)
{
    for (int i = 0; i < num_caixas; i++)
    {
        if (caixas[i].estado == 1)
        {
            printf("Caixa %d:\n", caixas[i].id);

            Cliente *cliente = caixas[i].fila->inicio;
            printf(" Prioridade 1 (Alta): \n");
            while (cliente != NULL)
            {
                if (cliente->prioridade == 1)
                {
                    printf("  Nome: %s - CPF: %s - Prioridade: %d - Itens: %d\n",
                           cliente->nome, cliente->cpf, cliente->prioridade, cliente->itens);
                }
                cliente = cliente->prox;
            }

            cliente = caixas[i].fila->inicio;
            printf(" Prioridade 2 (Média):\n");
            while (cliente != NULL)
            {
                if (cliente->prioridade == 2)
                {
                    printf("  Nome: %s - CPF: %s - Prioridade: %d - Itens: %d\n",
                           cliente->nome, cliente->cpf, cliente->prioridade, cliente->itens);
                }
                cliente = cliente->prox;
            }

            cliente = caixas[i].fila->inicio;
            printf(" Prioridade 3 (Baixa): \n");
            while (cliente != NULL)
            {
                if (cliente->prioridade == 3)
                {
                    printf("  Nome: %s - CPF: %s - Prioridade: %d - Itens: %d\n",
                           cliente->nome, cliente->cpf, cliente->prioridade, cliente->itens);
                }
                cliente = cliente->prox;
            }
        }
    }
}

void imprimir_status_caixas(Caixa *caixas, int num_caixas)
{
    for (int i = 0; i < num_caixas; i++)
    {

        int contagem = 0;
        Cliente *clienteAtual = caixas[i].fila->inicio;
        while (clienteAtual != NULL)
        {
            contagem++;
            clienteAtual = clienteAtual->prox;
        }

        printf("Caixa %d: %s - Clientes em espera: %d\n",
               caixas[i].id,
               caixas[i].estado ? "Aberto" : "Fechado",
               contagem);
    }
}
