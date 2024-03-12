#include <stdlib.h>
#include <stdio.h>

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int leftInd, int rightInd, int value) {
    int midInd = (leftInd + rightInd) / 2;
    if (leftInd > rightInd) {
        return -1;
    }
    else if (arr[midInd] == value) {
        return midInd;
    }
    else if (arr[midInd] < value) {
        return binarySearch(arr, midInd + 1, rightInd, value);
    }
    else {
        return binarySearch(arr, leftInd, midInd-1, value);
    }
}

int main() {
    int tab[] = { 97, 20, 100, 3, 71, 65, 3, 36, 85, 12, 29, 96, 72, 76, 36 };
    bubbleSort(tab, 15);
    for (int i = 0; i < sizeof(tab)/sizeof(int); i++) {
        printf("%d ", tab[i]);
    }
    int idx = binarySearch(tab, 0, sizeof(tab) / sizeof(int) - 1, 13);
    printf("\n%d", idx);
	return 0;
}