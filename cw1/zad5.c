#include <stdio.h>
#include <stdlib.h>

int main() {
    // ZADANIE  5
    int i, liczba = 10, suma = 0;
    if (liczba < 0) {
        printf("%d\n", 0);
    }
    else {
        for (i = 1; i < liczba; i++) {
            if (i % 15 == 0 || i % 3 == 0 || i % 5 == 0) {
                suma += i;
            }
        }
    }
    printf("%d\n", suma);
    return 0;
}