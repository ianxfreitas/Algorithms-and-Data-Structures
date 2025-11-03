/*Leia um numero inteiro e imprima o seu antecessor e o seu sucessor*/

#include <stdio.h>

int main()  {
    int num;

    printf("Digite o numero inteiro: ");
    scanf("%d", &num);

    printf("O antecessor de %d eh %d\n", num, num - 1);
    printf("O sucessor de %d eh %d\n", num, num + 1);

    return 0;
}