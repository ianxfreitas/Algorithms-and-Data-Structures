/*Leia um valor em real e a cotacao do dolar. Em seguida, imprima o valor correspondente ´
em dolares*/

#include <stdio.h>

int main() {
    float real, dolar;

    printf("Digite o valor em Real: ");
    scanf("%f", &real);

    dolar = real * 5.48;

    printf("O valor de Reais em Dolar eh: %.2f", dolar);

    return 0;
}