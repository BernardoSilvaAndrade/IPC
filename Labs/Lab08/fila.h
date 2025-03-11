#ifndef FILA_H
#define FILA_H

// Define o tipo de dados que será armazenado na fila
typedef struct pessoa
{
  int cpf;
  char nome[50];
  int prioridade;
} Pessoa;

// Define o nó da fila
typedef struct no
{
  Pessoa dado;
  struct no *prox; // O ponteiro para o próximo nó
} No;

// Define a fila
typedef struct fila
{
  No *inicio; // O ponteiro para o início da fila
  No *fim;    // O ponteiro para o fim da fila
} Fila;

// Cria uma fila vazia e retorna seu endereço
Fila *criar_fila();
void enfileirar(Fila *f, Pessoa dado);
Pessoa desenfileirar(Fila *f);
void mostrar_fila(Fila *f);
int fila_vazia(Fila *f);
void liberar_fila(Fila *f);

#endif
