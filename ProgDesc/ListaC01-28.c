/*Faca a leitura de tres valores e apresente como resultado a soma dos quadrados dos ˆ
tres valores lidos*/

#include <stdio.h>

int main()  {
    float valor1, valor2, valor3, valorSoma;
    
    printf("Digite o primeiro valor: ");
    scanf("%f", &valor1);

    printf("Digite o segundo valor: ");
    scanf("%f", &valor2);

    printf("Digite o terceiro valor: ");
    scanf("%f", &valor3);

    valorSoma = (valor1 * valor1) + (valor2 * valor2) + (valor3 * valor3);

    printf("Quadrado da Soma dos tres valores lidos eh igual a: %.2f", valorSoma);

    return 0;
}