#include <stdio.h>

void converter_comprimento();
void converter_massa();
void converter_temperatura();

int main() {
    int escolha;

    printf("### Conversor de Unidades ###\n");
    printf("Escolha uma opção:\n");
    printf("1 - Comprimento\n2 - Massa\n3 - Temperatura\n4 - Sair\n");

    scanf("%d", &escolha);

    while (escolha != 4) {
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
        printf("/nEscolha outra opcao ou 4 para sair:\n");
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

