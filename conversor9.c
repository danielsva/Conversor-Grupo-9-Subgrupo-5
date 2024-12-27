#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void converter_comprimento();
void converter_massa();
void converter_temperatura();
void conversorVelocidade();
void conversorVolume();
void conversor_de_bits();
void conversorTempo(); //Novo

int main() {
    int escolha;

    printf("### Conversor de Unidades ###\n");
    printf("Escolha uma opção:\n");
    printf("1 - Comprimento\n2 - Massa\n3 - Temperatura\n4 - Velocidade\n5- Volume\n 6- Bits\n 7-Tempo\n 8- Sair\n");

    scanf("%d", &escolha);

    while (escolha != 7) {
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
                conversor_de_bits();
            break;
            case 7:
                conversorTempo();
            break;
            default:
                printf(" Opcao invalida.\n");
        }
        printf("\nEscolha outra opcao ou 7 para sair:\n");
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

void converterTempo() {
    float tempo;
    printf("\nDigite o tempo em horas: ");
    scanf("%f", &tempo);
    printf("Minutos: %.2f \n",tempo * 60);
    printf("Segundos: %.2f \n",tempo * 3600);
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

void conversorVolume (){
    float resultado = -1;
    float valor;
    char unidadeOrigem[4], unidadeDestino[4];



    printf("qual a unidade de medida que voce deseja informar? (L, mL ou m3) \n");
    scanf("%s", unidadeOrigem);

    printf("qual o valor dessa unidade de medida?");
    scanf("%f", &valor);

    printf("para qual unidade de medida voce deseja converter?");
    scanf("%s", unidadeDestino);

    if(strcmp(unidadeOrigem, "L")== 0){
        if(strcmp(unidadeDestino, "mL") == 0){
            resultado = valor * 1000;
        } else{
            resultado = valor / 1000;
        }
    }

    if(strcmp(unidadeOrigem, "mL")== 0){
        if(strcmp(unidadeDestino, "L") == 0){
            resultado = valor / 1000;
        } else{
            resultado = valor / pow(10, 6);
        }
    }

    if(strcmp(unidadeOrigem, "m3")== 0){
        if(strcmp(unidadeDestino, "L") == 0){
            resultado = valor * 1000;
        } else{
            resultado = valor * pow(10, 6);
        }
    }

    if(resultado != -1.0){
        printf("Resultado: %0.2f %s", resultado, unidadeDestino);
    }
}

double bitsToBytes(double bits) {
    return bits / 8;
}

double bytesToKilobytes(double bytes) {
    return bytes / 1024;
}

double kilobytesToMegabytes(double kilobytes) {
    return kilobytes / 1024;
}

double megabytesToGigabytes(double megabytes) {
    return megabytes / 1024;
}

double gigabytesToTerabytes(double gigabytes) {
    return gigabytes / 1024;
}

void conversor_de_bits() {
    double value;
    int choice;

    printf("Conversor de Unidades de Dados\n");
    printf("Escolha a unidade de origem:\n");
    printf("1. Bits\n");
    printf("2. Bytes\n");
    printf("3. Kilobytes (KB)\n");
    printf("4. Megabytes (MB)\n");
    printf("5. Gigabytes (GB)\n");
    printf("6. Terabytes (TB)\n");
    printf("Escolha: ");
    scanf("%d", &choice);

    printf("Digite o valor a ser convertido: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            printf("%lf Bits = %lf Bytes\n", value, bitsToBytes(value));
            printf("%lf Bits = %lf Kilobytes (KB)\n", value, bytesToKilobytes(bitsToBytes(value)));
            printf("%lf Bits = %lf Megabytes (MB)\n", value, kilobytesToMegabytes(bytesToKilobytes(bitsToBytes(value))));
            printf("%lf Bits = %lf Gigabytes (GB)\n", value, megabytesToGigabytes(kilobytesToMegabytes(bytesToKilobytes(bitsToBytes(value)))));
            printf("%lf Bits = %lf Terabytes (TB)\n", value, gigabytesToTerabytes(megabytesToGigabytes(kilobytesToMegabytes(bytesToKilobytes(bitsToBytes(value))))));
            break;
        case 2:
            printf("%lf Bytes = %lf Bits\n", value, value * 8);
            printf("%lf Bytes = %lf Kilobytes (KB)\n", value, bytesToKilobytes(value));
            printf("%lf Bytes = %lf Megabytes (MB)\n", value, kilobytesToMegabytes(bytesToKilobytes(value)));
            printf("%lf Bytes = %lf Gigabytes (GB)\n", value, megabytesToGigabytes(kilobytesToMegabytes(bytesToKilobytes(value))));
            printf("%lf Bytes = %lf Terabytes (TB)\n", value, gigabytesToTerabytes(megabytesToGigabytes(kilobytesToMegabytes(bytesToKilobytes(value)))));
            break;
        case 3:
            printf("%lf Kilobytes (KB) = %lf Bytes\n", value, value * 1024);
            printf("%lf Kilobytes (KB) = %lf Bits\n", value, value * 1024 * 8);
            printf("%lf Kilobytes (KB) = %lf Megabytes (MB)\n", value, kilobytesToMegabytes(value));
            printf("%lf Kilobytes (KB) = %lf Gigabytes (GB)\n", value, megabytesToGigabytes(kilobytesToMegabytes(value)));
            printf("%lf Kilobytes (KB) = %lf Terabytes (TB)\n", value, gigabytesToTerabytes(megabytesToGigabytes(kilobytesToMegabytes(value))));
            break;
        case 4:
            printf("%lf Megabytes (MB) = %lf Kilobytes (KB)\n", value, value * 1024);
            printf("%lf Megabytes (MB) = %lf Bytes\n", value, value * 1024 * 1024);
            printf("%lf Megabytes (MB) = %lf Bits\n", value, value * 1024 * 1024 * 8);
            printf("%lf Megabytes (MB) = %lf Gigabytes (GB)\n", value, megabytesToGigabytes(value));
            printf("%lf Megabytes (MB) = %lf Terabytes (TB)\n", value, gigabytesToTerabytes(megabytesToGigabytes(value)));
            break;
        case 5:
            printf("%lf Gigabytes (GB) = %lf Megabytes (MB)\n", value, value * 1024);
            printf("%lf Gigabytes (GB) = %lf Kilobytes (KB)\n", value, value * 1024 * 1024);
            printf("%lf Gigabytes (GB) = %lf Bytes\n", value, value * 1024 * 1024 * 1024);
            printf("%lf Gigabytes (GB) = %lf Bits\n", value, value * 1024 * 1024 * 1024 * 8);
            printf("%lf Gigabytes (GB) = %lf Terabytes (TB)\n", value, gigabytesToTerabytes(value));
            break;
        case 6:
            printf("%lf Terabytes (TB) = %lf Gigabytes (GB)\n", value, value * 1024);
            printf("%lf Terabytes (TB) = %lf Megabytes (MB)\n", value, value * 1024 * 1024);
            printf("%lf Terabytes (TB) = %lf Kilobytes (KB)\n", value, value * 1024 * 1024 * 1024);
            printf("%lf Terabytes (TB) = %lf Bytes\n", value, value * 1024 * 1024 * 1024 * 1024);
            printf("%lf Terabytes (TB) = %lf Bits\n", value, value * 1024 * 1024 * 1024 * 1024 * 8);
            break;
        default:
            printf("Escolha inválida!\n");
    }
}

