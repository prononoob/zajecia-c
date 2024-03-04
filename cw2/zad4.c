#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Student {
	char* imie;
	float ocenaKoncowa;
};

void zamien(struct Student* x, struct Student* y) {
    struct Student temp = *x;
    *x = *y;
    *y = temp;
}

void babelkowe(struct Student *l, int rozmiar) {
    int i, j;
    bool zamienione;
    for (i = 0; i < rozmiar - 1; i++) {
        zamienione = false;
        for (j = 0; j < rozmiar - i - 1; j++) {
            if (l[j].ocenaKoncowa < l[j + 1].ocenaKoncowa) {
                zamien(&l[j], &l[j + 1]);
                zamienione = true;
            }
        }
        if (zamienione == false)
            break;
    }
}

int main() {
    struct Student listaStudentow[7] = {
        {"Jan Kowalski", 4.5},
        {"Maria Wojcik", 3.2},
        {"Piotr Wisniewski", 4.8},
        {"Magdalena Lewandowska", 2.9},
        {"Krzysztof Zielinski", 3.7},
        {"Anna Nowak", 4.1},
        {"Andrzej Kowalczyk", 3.5}
    };
    babelkowe(listaStudentow, 7);
    for (int i = 0; i < 7; i++) {
        printf("%s\t%f\n", listaStudentow[i].imie, listaStudentow[i].ocenaKoncowa);
    }
	return 0;
}