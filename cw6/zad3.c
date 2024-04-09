#include <stdlib.h>
#include <stdio.h>

int dodawanie(int x, int y) {
	return x + y;
}

int odejmowanie(int x, int y) {
	return x - y;
}

int mnozenie(int x, int y) {
	return x * y;
}

int main() {
	int (*wskaznikFunkcji)(int, int);
	int x, y, operacja;
	printf("\nWybierz operacje:\n\t1 - Dodawanie\n\t2 - Odejmowanie\n\t3 - Mnozenie\n");
	scanf("%d", &operacja);
	switch (operacja){
	case 1:
		wskaznikFunkcji = dodawanie;
		break;
	case 2:
		wskaznikFunkcji = odejmowanie;
		break;
	case 3:
		wskaznikFunkcji = mnozenie;
		break;
	default:
		break;
	}
	printf("Podaj 2 liczby: \n");
	scanf("%d %d", &x, &y);
	printf("\nWynik: %d", wskaznikFunkcji(x, y));
	return 0;
}