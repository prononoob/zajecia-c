#include <stdio.h>

// ponizsza funkcja zamieniaja dwie zmienne miejscami
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int* array, int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void permute(int* array, int start, int end) {
    int i;
    if (start == end) {
        printArray(array, end + 1);
    }
    else {
        for (i = start; i <= end; i++) {
            swap((array + start), (array + i));
            permute(array, start + 1, end);
            swap((array + start), (array + i));
        }
    }
}

int main() {
    int array[] = { 1, 2, 3, 4 };
    int n = sizeof(array) / sizeof(int);
    permute(array, 0, n - 1);
    return 0;
}
