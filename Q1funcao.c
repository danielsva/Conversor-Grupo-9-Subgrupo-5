#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p2lib.h"


Expressao *nova_expressao(char descricao[])
{
    Expressao *nova = (Expressao *)malloc(sizeof(Expressao));
    strcpy(nova->descricao, descricao);
    nova->prox = nova->ant = NULL;
    return nova;
}

void inicializar_lista(Lista *lista, int capacidade, int max_historico)
{
    lista->inicio = lista->fim = NULL;
    lista->capacidade = capacidade;
    lista->tamanho = 0;
    lista->historico = (Expressao **)malloc(max_historico * sizeof(Expressao *));
    lista->historico_index = 0;
    lista->historico_max = max_historico;
}

void atualizar_historico(Lista *lista, Expressao *expressao)
{
    if (lista->historico_index < lista->historico_max)
    {
        lista->historico[lista->historico_index++] = expressao;
    }
    else
    {
        for (int i = 1; i < lista->historico_max; i++)
        {
            lista->historico[i - 1] = lista->historico[i];
        }
        lista->historico[lista->historico_max - 1] = expressao;
    }
}

void inserir_no_final(Lista *lista, char descricao[])
{
    Expressao *nova = nova_expressao(descricao);
    if (lista->tamanho == lista->capacidade)
    {
        Expressao *remover = lista->fim;
        lista->fim = remover->ant;
        if (lista->fim) lista->fim->prox = NULL;
        else lista->inicio = NULL;
        free(remover);
        lista->tamanho--;
    }
    if (lista->fim)
    {
        lista->fim->prox = nova;
        nova->ant = lista->fim;
    }
    else
    {
        lista->inicio = nova;
    }
    lista->fim = nova;
    lista->tamanho++;
    atualizar_historico(lista, nova);
}

int aumentar_ranking(Lista *lista, Expressao *exp)
{
    if (exp->ant)
    {
        Expressao *anterior = exp->ant;
        anterior->prox = exp->prox;
        if (exp->prox) exp->prox->ant = anterior;
        else lista->fim = anterior;

        exp->ant = anterior->ant;
        exp->prox = anterior;

        if (anterior->ant) anterior->ant->prox = exp;
        else lista->inicio = exp;

        anterior->ant = exp;

        int nova_posicao = 1;
        Expressao *atual = lista->inicio;
        while (atual != exp)
        {
            atual = atual->prox;
            nova_posicao++;
        }
        return nova_posicao;
    }

    return 1;
}

int consultar(Lista *lista, char descricao[])
{
    Expressao *atual = lista->inicio;
    int posicao = 1;

    while (atual)
    {
        if (strcmp(atual->descricao, descricao) == 0)
        {

            int nova_posicao = aumentar_ranking(lista, atual);
            atualizar_historico(lista, atual);
            return nova_posicao;
        }
        atual = atual->prox;
        posicao++;
    }

    inserir_no_final(lista, descricao);
    return posicao;
}

void exibir_ordenado(Lista *lista)
{
    Expressao *atual = lista->inicio;
    while (atual)
    {
        printf("%s\n", atual->descricao);
        atual = atual->prox;
    }
}

void exibir_decrescente(Lista *lista)
{
    Expressao *atual = lista->fim;
    while (atual)
    {
        printf("%s\n", atual->descricao);
        atual = atual->ant;
    }
}

void exibir_historico(Lista *lista, int N)
{
    int inicio = lista->historico_index - N > 0 ? lista->historico_index - N : 0;
    for (int i = inicio; i < lista->historico_index; i++)
    {
        printf("%s\n", lista->historico[i]->descricao);
    }
}

void liberar_lista(Lista *lista)
{
    Expressao *atual = lista->inicio;
    while (atual)
    {
        Expressao *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(lista->historico);
}
