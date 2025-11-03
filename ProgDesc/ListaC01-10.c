/*Leia uma velocidade em km/h (quilometros por hora) e apresente-a convertida em m/s ˆ
(metros por segundo). A formula de convers ´ ao˜ e: ´ M = K/3.6, sendo K a velocidade em
km/h e M em m/s*/

#include <stdio.h>

int main()  {
    float km, ms;

    printf("Digite a veloidade em km/h: ");
    scanf("%f", &km);

    ms = km / 3.6;

    printf("A velocidade convertida eh: %.2f", ms);

    return 0;
}