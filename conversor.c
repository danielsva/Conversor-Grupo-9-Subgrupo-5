#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void converter_comprimento();
void converter_massa();
void converter_temperatura();
void conversorVelocidade();
void conversorVolume();
void conversorArea();
void conversorTempo();

int main() {
    int escolha;

    printf("### Conversor de Unidades ###\n");
    printf("Escolha uma opcao:\n");
    printf("1 - Comprimento\n2 - Massa\n3 - Temperatura\n4 - Velocidade\n5 - Volume\n6 - Area\n7 - Tempo\n8 - Sair\n");

    scanf("%d", &escolha);

    while (escolha != 8) {
        switch (escolha) {
            case 1:
                converter_comprimento();
                break;
            case 2:
                converter_massa();
                break;
            case 3:
                converter_temperatura();
                break;
            case 4:
                conversorVelocidade();
                break;
            case 5:
                conversorVolume();
                break;
            case 6:
                conversorArea();
                break;
            case 7:
                conversorTempo();
                break;
            default:
                printf("Opcao invalida.\n");
        }
        printf("\nEscolha outra opcao ou 8 para sair:\n");
        scanf("%d", &escolha);
    }

    return 0;
}

void conversorVolume() {
    float resultado = -1;
    float valor;
    char unidadeOrigem[4], unidadeDestino[4];
    printf("Qual a unidade de medida que voce deseja informar? (L, mL ou m3) \n");
    scanf("%s", unidadeOrigem);
    printf("Qual o valor dessa unidade de medida?\n");
    scanf("%f", &valor);
    printf("Para qual unidade de medida voce deseja converter?\n");
    scanf("%s", unidadeDestino);
    if (strcmp(unidadeOrigem, "L") == 0) {
        if (strcmp(unidadeDestino, "mL") == 0) {
            resultado = valor * 1000;
        } else {
            resultado = valor / 1000;
        }
    }
    if (strcmp(unidadeOrigem, "mL") == 0) {
        if (strcmp(unidadeDestino, "L") == 0) {
            resultado = valor / 1000;
        } else {
            resultado = valor / pow(10, 6);
        }
    }
    if (strcmp(unidadeOrigem, "m3") == 0) {
        if (strcmp(unidadeDestino, "L") == 0) {
            resultado = valor * 1000;
        } else {
            resultado = valor * pow(10, 6);
        }
    }
    if (resultado != -1.0) {
        printf("Resultado: %0.2f %s\n", resultado, unidadeDestino);
    } else {
        printf("Conversao invalida.\n");
    }
}

void conversorArea() {
    float resultado = -1;
    float valor;
    char unidadeOrigem[4], unidadeDestino[4];
    printf("Qual a unidade de medida que voce deseja informar? (m2 ou cm2) \n");
    scanf("%s", unidadeOrigem);
    printf("Qual o valor dessa unidade de medida?\n");
    scanf("%f", &valor);
    printf("Para qual unidade de medida voce deseja converter?\n");
    scanf("%s", unidadeDestino);
    if (strcmp(unidadeOrigem, "m2") == 0) {
        if (strcmp(unidadeDestino, "cm2") == 0) {
            resultado = valor * 10000;
        }
    }
    if (strcmp(unidadeOrigem, "cm2") == 0) {
        if (strcmp(unidadeDestino, "m2") == 0) {
            resultado = valor / 10000;
        }
    }
    if (resultado != -1.0) {
        printf("Resultado: %0.2f %s\n", resultado, unidadeDestino);
    } else {
        printf("Conversao invalida.\n");
    }
}

void conversorTempo() {
    float resultado = -1;
    float valor;
    char unidadeOrigem[10], unidadeDestino[10];
    printf("Qual a unidade de medida que voce deseja informar? (s, min ou h) \n");
    scanf("%s", unidadeOrigem);
    printf("Qual o valor dessa unidade de medida?\n");
    scanf("%f", &valor);
    printf("Para qual unidade de medida voce deseja converter?\n");
    scanf("%s", unidadeDestino);
    if (strcmp(unidadeOrigem, "s") == 0) {
        if (strcmp(unidadeDestino, "min") == 0) {
            resultado = valor / 60;
        } else if (strcmp(unidadeDestino, "h") == 0) {
            resultado = valor / 3600;
        }
    }
    if (strcmp(unidadeOrigem, "min") == 0) {
        if (strcmp(unidadeDestino, "s") == 0) {
            resultado = valor * 60;
        } else if (strcmp(unidadeDestino, "h") == 0) {
            resultado = valor / 60;
        }
    }
    if (strcmp(unidadeOrigem, "h") == 0) {
        if (strcmp(unidadeDestino, "s") == 0) {
            resultado = valor * 3600;
        } else if (strcmp(unidadeDestino, "min") == 0) {
            resultado = valor * 60;
        }
    }
    if (resultado != -1.0) {
        printf("Resultado: %0.2f %s\n", resultado, unidadeDestino);
    } else {
        printf("Conversao invalida.\n");
    }
}
