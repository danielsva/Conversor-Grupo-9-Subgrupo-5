#include <stdio.h>
#include <stdlib.h>

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

int main() {
    conversorVelocidade();
    return 0;
}
