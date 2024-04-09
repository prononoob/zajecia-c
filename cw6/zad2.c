#include <stdlib.h>
#include <stdio.h>

int main() {
	int tab[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int *tabPointer = &tab[0];
	for (int i = 0; i < sizeof(tab)/sizeof(int); i++) {
		printf("%d\n", *tabPointer);
		tabPointer++;
	}
	return 0;
}