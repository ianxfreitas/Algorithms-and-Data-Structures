/*Leia uma distancia em milhas e apresente-a convertida em quilometros. A formula de 
conversao eh: K = 1, 61 ∗ M, sendo K a distancia em quilometros e M em milhas*/

#include <stdio.h>

int main() {
    float milhas, km;

    printf("Digite a distancia em milhas: ");
    scanf("%f", &milhas);

    km = 1.61 * milhas;

    printf("A distancia convertida para quilometros eh: %.2f", km);

    return 0;
}