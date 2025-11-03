#include <stdio.h>

int main()  {
    int num;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    if (num % 2 == 0){
      printf("O %d eh par!", num);
    } else {
      printf("O %d eh impar!", num);
    }
    return 0;
}