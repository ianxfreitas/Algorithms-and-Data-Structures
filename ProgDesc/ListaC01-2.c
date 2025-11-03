//Faça um programa que leia um numero real e o imprima.

#include <stdio.h>

int main()  {
    float numero;

    printf ("Digite um numero: ");
    scanf("%f", &numero);

    printf("Voce digitou o numero: %.2f\n", numero);

    return 0;
}