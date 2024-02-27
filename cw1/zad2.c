#include <stdio.h>
#include <stdlib.h>

int main() {
    //ZAD 2
    int grades[2][5] = { {3,3,4,5,4}, {1,4,5,3,4} };
    int i;
    int arrLen = sizeof(grades[0]) / sizeof(int);
    float suma = 0;
    for (i = 0; i < 5; i++) {
        suma += grades[0][i];
    }
    float wynik = suma / arrLen;
    printf("Srednia z matematyki %f\n", wynik);

    suma = 0;
    for (i = 0; i < 5; i++) {
        suma += grades[1][i];
    }
    wynik = suma / arrLen;
    printf("Srednia z fizyki %f\n", wynik);
    return 0;
}