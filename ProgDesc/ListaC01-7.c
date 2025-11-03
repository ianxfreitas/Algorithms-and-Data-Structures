/*Leia uma temperatura em graus Fahrenheit e apresente-a convertida em graus Celsius.
A formula de conversao e: C = 5.0 ∗ (F − 32.0)/9.0, sendo C a temperatura em Celsius
e F a temperatura em Fahrenheit.*/

#include <stdio.h>

int main()  {
    float fahren, celsius;

    printf("Digite a temperatura em graus Fahrenheit: ");
    scanf("%f", &fahren);

    celsius = 5.0 * (fahren - 32.0) / 9.0;

    printf("A temperatura em graus Celsius eh: %.2f", celsius);

    return 0;
}