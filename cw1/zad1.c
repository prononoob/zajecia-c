#include <stdio.h>
#include <stdlib.h>


int main() {
	// ZAD 1
	char str[100];

	printf("Wpisz imie: ");
	scanf("%s", str, sizeof(str));

	printf("twoje imie: %s\n", str);
	return 0;
}
