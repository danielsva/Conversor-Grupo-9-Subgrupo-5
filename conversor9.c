#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void converter_comprimento();
void converter_massa();
void converter_temperatura();
void conversorVelocidade();
void conversorVolume();
void converter_area();
void converter_tempo();

int main() {
    int escolha;

    printf("### Conversor de Unidades ###\n");
    printf("Escolha uma opção:\n");
    printf("1 - Comprimento\n2 - Massa\n3 - Temperatura\n4 - Velocidade\n5 - Volume\n6 - Área\n7 - Tempo\n8 - Sair\n");

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
                converter_area();
                break;
            case 7:
                converter_tempo();
                break;
            default:
                printf("Opção inválida.\n");
        }
        printf("\nEscolha outra opção ou 8 para sair:\n");
        scanf("%d", &escolha);
    }

    printf("Programa encerrado.\n");
    return 0;
}

void converter_comprimento() {
    float metros;
    printf("\nDigite o valor em metros: ");
    scanf("%f", &metros);
    printf("Centímetros: %.2f cm\n", metros * 100);
    printf("Milímetros: %.2f mm\n", metros * 1000);
}

void converter_massa() {
    float kg;
    printf("\nDigite o valor em quilogramas: ");
    scanf("%f", &kg);
    printf("Gramas: %.2f g\n", kg * 1000);
    printf("Toneladas: %.3f t\n", kg / 1000);
}

void converter_temperatura() {
    float celsius;
    printf("\nDigite a temperatura em Celsius: ");
    scanf("%f", &celsius);
    printf("Fahrenheit: %.2f F\n", (celsius * 9 / 5) + 32);
    printf("Kelvin: %.2f K\n", celsius + 273.15);
}

void conversorVelocidade() {
    int esci, escf, i;
    float valor, resultado;

    i = 1;
    while (i) {
        system("cls");
        printf("\n---------------- Conversor de Velocidade ----------------\n");
        printf("\n1 - km/h\n2 - m/s\n3 - mph\n");
        printf("\nDigite a unidade inicial: ");
        scanf("%d", &esci);
        if (esci >= 1 && esci <= 3) {
            i = 0;
        }
    }

    i = 1;
    while (i) {
        system("cls");
        printf("\n---------------- Conversor de Velocidade ----------------\n");
        printf("\n1 - km/h\n2 - m/s\n3 - mph\n");
        printf("\nDigite a unidade final: ");
        scanf("%d", &escf);
        if (escf >= 1 && escf <= 3) {
            i = 0;
        }
    }

    system("cls");
    printf("\n---------------- Conversor de Velocidade ----------------\n");
    printf("\nDigite a velocidade na unidade inicial: ");
    scanf("%f", &valor);

    if (esci == 1 && escf == 2) {
        resultado = valor / 3.6; // km/h para m/s
    } else if (esci == 1 && escf == 3) {
        resultado = valor / 1.609; // km/h para mph
    } else if (esci == 2 && escf == 1) {
        resultado = valor * 3.6; // m/s para km/h
    } else if (esci == 2 && escf == 3) {
        resultado = valor * 2.237; // m/s para mph
    } else if (esci == 3 && escf == 1) {
        resultado = valor * 1.609; // mph para km/h
    } else if (esci == 3 && escf == 2) {
        resultado = valor / 2.237; // mph para m/s
    } else {
        resultado = valor; // Unidades iguais
    }

    printf("\nO resultado da conversão é: %f\n\n", resultado);
}

void conversorVolume() {
    float resultado = -1;
    float valor;
    char unidadeOrigem[4], unidadeDestino[4];

    printf("Qual a unidade de medida que você deseja informar? (L, mL ou m³) \n");
    scanf("%s", unidadeOrigem);

    printf("Qual o valor dessa unidade de medida? ");
    scanf("%f", &valor);

    printf("Para qual unidade de medida você deseja converter? ");
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

    if (strcmp(unidadeOrigem, "m³") == 0) {
        if (strcmp(unidadeDestino, "L") == 0) {
            resultado = valor * 1000;
        } else {
            resultado = valor * pow(10, 6);
        }
    }

    if (resultado != -1.0) {
        printf("Resultado: %.2f %s\n", resultado, unidadeDestino);
    }
}

void converter_area() {
    float metrosQuadrados, centimetrosQuadrados, hectares;
    printf("\nDigite o valor em metros quadrados: ");
    scanf("%f", &metrosQuadrados);

    centimetrosQuadrados = metrosQuadrados * 10000;
    hectares = metrosQuadrados / 10000;

    printf("Centímetros quadrados: %.2f cm²\n", centimetrosQuadrados);
    printf("Hectares: %.4f ha\n", hectares);
}

void converter_tempo() {
    float segundos, minutos, horas;
    printf("\nDigite o valor em segundos: ");
    scanf("%f", &segundos);

    minutos = segundos / 60;
    horas = minutos / 60;

    printf("Minutos: %.2f min\n", minutos);
    printf("Horas: %.2f h\n", horas);
}
