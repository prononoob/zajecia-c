#include <stdlib.h>
#include <stdio.h>

int main() {
    // ZADANIE 4
    int i;
    for (i = 1; i <= 200; i++) {
        printf("%d ", i);
        if (i % 5 == 0) {
            printf("Foo");
        }
        if (i % 7 == 0) {
            printf("Bar");
        }
        printf("\n");
    }
    return 0;
}