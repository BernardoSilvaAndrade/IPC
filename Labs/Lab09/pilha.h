#ifndef PILHA_H
#define PILHA_H

typedef struct autor
{
    char nome[100];
    int id;
} Autor;

typedef struct doc
{
    int id;
    char titulo[100];
    Autor *autores;
    int num_autores;
} Doc;

typedef struct nodo
{
    Doc doc;
    struct nodo *prox;
} Nodo;

typedef struct Pilha
{
    Nodo *topo;
} Pilha;

void criarPilha(Pilha *pilha);
void empilhar(Pilha *pilha, Doc doc);
void desempilhar(Pilha *pilha);
void mostrarTopo(Pilha *pilha);
int estaVazia(Pilha *pilha);
void salvarArquivo(Pilha *pilha, const char *nomeArquivo);
void carregarArquivo(Pilha *pilha, const char *nomeArquivo);

#endif
