#include <stdio.h>
#include "p2lib.h"


int main()
{
    int opcao, N, capacidade, max_historico, posicao;
    char descricao[81];

    printf("Digite a capacidade maxima da lista: ");
    scanf("%d", &capacidade);
    printf("Digite o tamanho maximo do historico: ");
    scanf("%d", &max_historico);

    Lista lista;
    inicializar_lista(&lista, capacidade, max_historico);

    do
    {
        printf("\n1. Consultar uma expressao\n");
        printf("2. Exibir todas as expressoes (crescente)\n");
        printf("3. Exibir todas as expressoes (decrescente)\n");
        printf("4. Exibir historico das ultimas N consultas\n");
        printf("5. Encerrar o programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite a expressao: ");
            scanf(" %80[^\n]", descricao);
            posicao = consultar(&lista, descricao);
            printf(" posicao: %d\n", posicao);
            break;
        case 2:
            exibir_ordenado(&lista);
            break;
        case 3:
            exibir_decrescente(&lista);
            break;
        case 4:
            printf("Quantas consultas voce deseja ver? ");
            scanf("%d", &N);
            exibir_historico(&lista, N);
            break;
        case 5:
            liberar_lista(&lista);
            printf("Programa encerrado.\n");
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }
    }
    while (opcao != 5);

    return 0;
}
