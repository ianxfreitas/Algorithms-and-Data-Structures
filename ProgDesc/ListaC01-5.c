// Leia um numero real e imprima a quinta parte deste numero

#include <stdio.h>

int main()  {
    float numero;

    printf("Digite um numero: ");
    scanf("%f", &numero);
    
    printf("A quinta parte de %.2f eh: %.2f\n", numero, numero / 5);

    return 0;
}