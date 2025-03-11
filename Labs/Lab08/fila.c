#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

// Cria uma fila vazia e retorna seu endereço
Fila *criar_fila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila)); // Aloca memória para a fila
    if (f == NULL)
    { // Verifica se a alocação foi bem sucedida
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    f->inicio = NULL; // Inicializa o início da fila como NULL
    f->fim = NULL;    // Inicializa o fim da fila como NULL
    return f;
}

// Insere um dado no fim da fila
void enfileirar(Fila *f, Pessoa dado)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }

    novo->dado = dado;
    novo->prox = NULL;

    if (fila_vazia(f))
    {
        f->inicio = novo;
        f->fim = novo;
    }
    else if (dado.prioridade == 1)
    {
        // Insere o novo nó no início da fila
        novo->prox = f->inicio;
        f->inicio = novo;
    }
    else
    {
        // Insere o novo nó no final da fila
        f->fim->prox = novo;
        f->fim = novo;
    }
}

// Remove um dado do início da fila e retorna seu valor
Pessoa desenfileirar(Fila *f)
{
    if (!fila_vazia(f))
    {
        No *aux = f->inicio;
        Pessoa dado = aux->dado;
        f->inicio = f->inicio->prox;
        if (fila_vazia(f))
        {
            f->fim = NULL;
        }
        free(aux);
        return dado;
    }
    else
    {
        printf("Fila inexistente ou vazia.\n");
        return (Pessoa){-1}; // CPF -1 indica erro
    }
}

// Imprime os dados da fila na ordem do início ao fim
void mostrar_fila(Fila *f)
{
    if (!fila_vazia(f))
    {
        No *aux = f->inicio; // Cria um ponteiro auxiliar para percorrer a fila
        printf("Fila:");
        while (aux != NULL)
        {
            printf("\nCPF: %d\n", aux->dado.cpf);
            printf("Nome: %s\n", aux->dado.nome);
            aux = aux->prox;
        }
        printf("\n");
    }
    else
    {
        printf("Fila inexistente ou vazia.\n");
    }
}

// Verifica se a fila está vazia e retorna 1 se sim, 0 se não
int fila_vazia(Fila *f)
{
    return f->inicio == NULL;
}

// Libera a memória de uma fila e seus nós
void liberar_fila(Fila *f)
{
    if (f != NULL)
    {
        No *aux;
        while (f->inicio != NULL)
        {
            aux = f->inicio;
            f->inicio = f->inicio->prox;
            free(aux);
        }
        free(f);
    }
}
