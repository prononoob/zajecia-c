#include <stdlib.h>
#include <stdio.h>

union dane {
	int calkowita;
	float zmiennoPrzecinkowa;
	char znak;
};

int main() {
	union dane d1;
	d1.calkowita = 44;
	printf("liczba calkowita w union: %d\n", d1.calkowita);
	d1.zmiennoPrzecinkowa = 3.14;
	printf("liczba float w union: %f\n", d1.zmiennoPrzecinkowa);
	d1.znak = 'A';
	printf("znak w union: %c\n", d1.znak);
	return 0;
}