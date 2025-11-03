/*Escreva um programa que, dados dois numeros inteiros, mostre na tela o maior deles,
assim como a diferenca existente entre ambos*/

#include <stdio.h>

int main()  {
  int num1, num2;

  printf("Digite o primeiro numero inteiro: ");
  scanf("%d", &num1);

  printf("Digite o segundo numero inteiro: ");
  scanf("%d", &num2);

  if ( num1 > num2){
    printf("O %d eh maior que o %d", num1, num2);
  } else if ( num2 > num1) {
    printf("O %d eh maior que o %d", num2, num1);
  } else {
    printf("O %d e o %d sao o iguais!", num1, num2);
  }
  return 0;
}