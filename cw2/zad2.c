#include <stdlib.h>
#include <stdio.h>

void podwoj(float* liczba) {
	*liczba *= 2;
}

int main() {
	float i = 2;
	podwoj(&i);
	printf("%f", i);
}