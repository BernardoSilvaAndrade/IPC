#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void criarPilha(Pilha *pilha)
{
    pilha->topo = NULL;
}

void empilhar(Pilha *pilha, Doc doc)
{
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    if (novo == NULL)
    {
        printf("Memória insuficiente.\n");
        return;
    }
    novo->doc = doc;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

void desempilhar(Pilha *pilha)
{
    if (estaVazia(pilha))
    {
        printf("Pilha vazia.\n");
        return;
    }

    Nodo *temp = pilha->topo;
    pilha->topo = pilha->topo->prox;

    free(temp->doc.autores);
    free(temp);
}

void carregarArquivo(Pilha *pilha, const char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (!estaVazia(pilha))
    {
        desempilhar(pilha);
    }

    Doc doc;
    while (fread(&doc, sizeof(Doc), 1, arquivo) == 1)
    {
        doc.autores = (Autor *)malloc(doc.num_autores * sizeof(Autor));
        fread(doc.autores, sizeof(Autor), doc.num_autores, arquivo);
        empilhar(pilha, doc);
    }

    fclose(arquivo);
}

void salvarArquivo(Pilha *pilha, const char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Nodo *atual = pilha->topo;
    while (atual != NULL)
    {
        fwrite(&(atual->doc), sizeof(Doc), 1, arquivo);
        fwrite(atual->doc.autores, sizeof(Autor), atual->doc.num_autores, arquivo);
        atual = atual->prox;
    }

    fclose(arquivo);
}

void mostrarTopo(Pilha *pilha)
{
    if (estaVazia(pilha))
    {
        printf("A pilha está vazia.\n");
    }
    else
    {
        Doc *topoDoc = &(pilha->topo->doc);
        printf("Documento no topo:\nID: %d\nTítulo: %s\n", topoDoc->id, topoDoc->titulo);
        printf("Autores:\n");
        for (int i = 0; i < topoDoc->num_autores; i++)
        {
            printf("ID do autor: %d, Nome do autor: %s\n", topoDoc->autores[i].id, topoDoc->autores[i].nome);
        }
    }
}

int estaVazia(Pilha *pilha)
{
    return (pilha->topo == NULL);
}
