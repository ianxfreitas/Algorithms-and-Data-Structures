#include <stdio.h>
#include <stdbool.h>

bool lemonadeChange(int* bills, int billsSize) {
    int cinco = 0;
    int dez = 0;

    for (int i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            cinco++;
        } else if (bills[i] == 10) {
            if (cinco == 0) {
                return false;
            }
            cinco--;
            dez++;
        } else {
            if (dez > 0 && cinco > 0) {
                dez--;
                cinco--;
            } else if (cinco >= 3) {
                cinco -= 3;
            } else {
                return false;
            }
        }
        if (cinco < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int bills1[] = {5, 5, 5, 10, 20};
    int bills2[] = {5, 5, 10, 10, 20};

    if (lemonadeChange(bills1, 5)) {
        printf("Exemplo 1: troco possivel \n");
    } else {
        printf("Exemplo 1: troco impossivel \n");
    }

    if (lemonadeChange(bills2, 5)) {
        printf("Exemplo 2: troco possivel \n");
    } else {
        printf("Exemplo 2: troco impossivel \n");
    }

    return 0;
}
