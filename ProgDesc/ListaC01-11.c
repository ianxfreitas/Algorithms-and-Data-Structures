/*Leia uma velocidade em m/s (metros por segundo) e apresente-a convertida em km/h
(quilometros por hora). A f ˆ ormula de convers ´ ao˜ e: ´ K = M ∗ 3.6, sendo K a velocidade
em km/h e M em m/s*/

#include <stdio.h>

int main()  {
    float ms, km;

    printf("Digite a velocidade em ms: ");
    scanf("%f", &ms);

    km = ms * 3.6;

    printf("A velocidade em metros por segundo eh: %.2f", km);

    return 0;
}