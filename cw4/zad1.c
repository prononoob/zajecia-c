#include <stdlib.h>
#include <stdio.h>

int factorial(int x) {
	if (x > 0) {
		x *= factorial(x - 1);
	}
	else if (x == 0) {
		return 1;
	}
	return x;
}

int main() {
	int wynik = factorial(3);
	printf("%d", wynik);
	return 0;
}