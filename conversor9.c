#include <stdio.h>
#include <stdlib.h>

void converter_comprimento();
void converter_massa();
void converter_temperatura();
void conversorVelocidade();

int main() {
    int escolha;

    printf("### Conversor de Unidades ###\n");
    printf("Escolha uma opção:\n");
    printf("1 - Comprimento\n2 - Massa\n3 - Temperatura\n4 - Velocidade\n 5- Sair\n");

    scanf("%d", &escolha);

    while (escolha != 5) {
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
            default:
                printf(" Opcao invalida.\n");
        }
        printf("/nEscolha outra opcao ou 5 para sair:\n");
        scanf("%d", &escolha);

            case 4:
conversorVelocidade();
                break;
            default:
                printf(" Opcao invalida.\n");
        }
        printf("/nEscolha outra opcao ou 5 para sair:\n");
        scanf("%d", &escolha);
    }

    printf("Programa encerrado.\n");
    return 0;
}

void converter_comprimento() {
    float metros;
    printf("\nDigite o valor em metros: ");
    scanf("%f", &metros);
    printf("Centimetros: %.2f cm\n",metros * 1000);
    printf("Milimetros: %.2f mm\n", metros * 1000);
}

void converter_massa() {
    float kg;
    printf("\nDigite o valor em quilogramas: ");
    scanf("%f", &kg);
    printf("Gramas: %2.f g\n", kg * 1000);
    printf("Toneladas: %.3f t\n", kg / 1000);
}

void converter_temperatura() {
    float celsius;
    printf("\nDigite a temperatura em Celsios: ");
    scanf("%f", &celsius);
    printf("Fahrenheit: %.2f F\n", (celsius * 9/5) + 32);
    printf("Kelvin: %.2f K\n", celsius + 273.15);
}

void conversorVelocidade(){
    int esci, escf, i;
    float valor, resultado;

    i = 1;
    while(i){
        system("cls");
        printf("\n---------------- Conversor de Velocidade ----------------\n");
        printf("\n1 - km/h\n2 - m/s\n3 - mph\n");
        printf("\nDigite a unidade inicial: ");
        scanf("%d",&esci);
        if(esci >= 1 && esci <= 3){
            i = 0;
        }
    }

    i = 1;
    while(i){
        system("cls");
        printf("\n---------------- Conversor de Velocidade ----------------\n");
        printf("\n1 - km/h\n2 - m/s\n3 - mph\n");
        printf("\nDigite a unidade final: ");
        scanf("%d",&escf);
        if(escf >= 1 && escf <= 3){
            i = 0;
        }
    }

        system("cls");
    printf("\n---------------- Conversor de Velocidade ----------------\n");
    printf("\nDigite a velocidade na unidade inicial: ");
    scanf("%f",&valor);

    if (esci == 1 && escf == 2) { // km/h para m/s
        resultado = valor / 3.6;
    } else if (esci == 1 && escf == 3) { // km/h para mph
        resultado = valor / 1.609;
    } else if (esci == 2 && escf == 1) { // m/s para km/h
        resultado = valor * 3.6;
    } else if (esci == 2 && escf == 3) { // m/s para mph
        resultado = valor * 2.237;
    } else if (esci == 3 && escf == 1) { // mph para km/h
        resultado = valor * 1.609;
    } else if (esci == 3 && escf == 2) { // mph para m/s
        resultado = valor / 2.237;
    } else {
        resultado = valor;
    }

    printf("\nO resultado da conversao eh: %f\n\n", resultado);
}

