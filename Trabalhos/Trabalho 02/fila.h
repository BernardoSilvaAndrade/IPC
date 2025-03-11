#ifndef FILA_H
#define FILA_H

#define MAX_CAIXAS 5

typedef struct Cliente
{
    char nome[100];
    char cpf[12];
    int prioridade;
    int itens;
    struct Cliente *prox;
} Cliente;

typedef struct FilaPrioridade
{
    Cliente *inicio;
    Cliente *fim;
} FilaPrioridade;

typedef struct Caixa
{
    int id;
    int estado; // 0 = fechado, 1 = aberto
    FilaPrioridade *fila;
} Caixa;

FilaPrioridade *criar_fila();
void cadastrarCliente(FilaPrioridade *fila, Cliente *cliente);
Cliente *atenderCliente(FilaPrioridade *fila);
void imprimir_clientes_em_espera(Caixa *caixas, int num_caixas);
void imprimir_status_caixas(Caixa *caixas, int num_caixas);
void fecharCaixa(Caixa *caixas, int num_caixas, int caixa_id);

#endif
