/*. Leia um angulo em graus e apresente-o convertido em radianos. A formula de conversao
e: R = G ∗ π/180, sendo G o angulo em graus e R em radianos e π = 3.14*/

#include <stdio.h>

int main()  {
    float graus, radianos, pi = 3.14;

    printf("Digite o angulo em graus: ");
    scanf("%f", &graus);

    radianos = graus * pi/180;

    printf("O angulo em radianos eh: %.2f", radianos);

    return 0;
}