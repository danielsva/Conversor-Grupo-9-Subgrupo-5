#ifndef P2LIB_H_INCLUDED
#define P2LIB_H_INCLUDED


typedef struct expressao {
    char descricao[81];
    struct expressao *prox, *ant;
} Expressao;

typedef struct {
    Expressao *inicio, *fim;
    int capacidade, tamanho;
    Expressao **historico;
    int historico_index, historico_max;
} Lista;


void inicializar_lista(Lista *lista, int capacidade, int max_historico);
int consultar(Lista *lista, char descricao[]);
void exibir_ordenado(Lista *lista);
void exibir_decrescente(Lista *lista);
void exibir_historico(Lista *lista, int N);
void liberar_lista(Lista *lista);


#endif
