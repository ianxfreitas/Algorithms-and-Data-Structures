//Leia um numero real e imprima o resultado do quadrado desse numero

#include <stdio.h>

int main()  {
    float numero, resultado;

    printf("Digite um numero: ");
    scanf("%f", &numero);

    resultado = numero * numero;

    printf("O resultado do quadrado do numero escrito: %.2f", resultado);

    return 0;
}