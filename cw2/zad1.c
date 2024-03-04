#include <stdlib.h>
#include <stdio.h>

int main() {
	int zmienna = 4;
	int* pZmienna = &zmienna;
	(*pZmienna)++;
	printf("%d\t%d\n", zmienna, *pZmienna);
}