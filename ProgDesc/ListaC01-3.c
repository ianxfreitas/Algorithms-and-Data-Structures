//Peça ao usuario para digitar tres valores inteiros e imprima a soma deles.

#include <stdio.h>

int main()  {
    int valor1, valor2, valor3, valorTotal;

    printf("Digite o primeiro valor inteiro: ");
    scanf("%d", &valor1);

    printf("Digite o segundo valor inteiro: ");
    scanf("%d", &valor2);

    printf("Digite o terceiro valor inteiro: ");
    scanf("%d", &valor3);

    valorTotal = valor1 + valor2 + valor3;

    printf("O resultado da soma: %d", valorTotal);

    return 0;
}