#include <stdlib.h>
#include <stdio.h>

int main() {
    // ZADANIE 3
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int arraySize = sizeof(array) / sizeof(array[0]);
    float wynik = 1;
    int i;
    for (i = 0; i < arraySize; i++) {
        wynik *= array[i];
    }
    printf("%f\n", wynik);
    return 0;
}