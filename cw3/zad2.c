#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int liczbaWierszy, liczbaKolumn, i, j;
    int** macierz;

    printf("Podaj liczbe wierszy macierzy: ");
    scanf("%d", &liczbaWierszy);
    printf("Podaj liczbe kolumn macierzy: ");
    scanf("%d", &liczbaKolumn);

    // Alokacja pamieci
    macierz = (int**)malloc(liczbaWierszy * sizeof(int*));
    for (i = 0; i < liczbaWierszy; i++) {
        macierz[i] = (int*)malloc(liczbaKolumn * sizeof(int));
    }

    srand(time(NULL));

    // Wypelnianie macierzy losowymi liczbami i printowanie ich
    printf("Wygenerowana macierz:\n");
    for (i = 0; i < liczbaWierszy; i++) {
        for (j = 0; j < liczbaKolumn; j++) {
            macierz[i][j] = rand() % 100;
            printf("%d\t", macierz[i][j]);
        }
        printf("\n");
    }

    // Zwolnienie pamieci
    for (i = 0; i < liczbaWierszy; i++) {
        free(macierz[i]);
    }
    free(macierz);

    return 0;
}