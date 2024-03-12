#include <stdio.h>
#include <stdlib.h>

void printTriangle(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void trojkatPascala(int n) {
    // Alokuje pamiec dla wskaznikow do kazdego wiersza
    int** arr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        // Alokuje pamiec dla kazdego wiersza
        arr[i] = (int*)malloc((i + 1) * sizeof(int));
        arr[i][0] = 1; // Pierwsza wartosc w kazdym wierszu to zawsze 1
        arr[i][i] = 1; // Ostatnia wartosc w kazdym wierszu tez jest 1

        // Uzupelniamy srodkowe wartosci wiersza, jesci istnieja
        for (int j = 1; j < i; j++) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }

    printTriangle(arr, n);

    // Zwolnienie pamieci
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main() {
    trojkatPascala(5);
    return 0;
}