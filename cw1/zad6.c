#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define LICZBA_RUND 10

struct scoreboard {
	int s[LICZBA_RUND];
	// int runda uzywam do wsadzania wynikow do powyzszego arraya na kolejne pozycje
	int runda;
};

void wyswietlWyniki(struct scoreboard sb) {
	int i, sumaW = 0, sumaP = 0, sumaR = 0;
	// sumuje ilosc wygranych, przegranych i remisow i wyswietla je w konsoli
	for (i = 0; i < LICZBA_RUND; i++) {
		if (sb.s[i] == 1) {
			sumaW++;
		}
		else if (sb.s[i] == 2) {
			sumaP++;
		}
		else if (sb.s[i] == 3) {
			sumaR++;
		}
		else {
			break;
		}
	}
	printf("\nwygrales %d\nprzegrales %d\nzremisowales %d\n", sumaW, sumaP, sumaR);
}

int main() {
	int i, num, r;
	struct scoreboard wyniki;
	wyniki.runda = 0;
	srand(time(NULL));

	while(wyniki.runda < LICZBA_RUND) {
		printf("\n1 - graj\n2 - wyswietl wyniki\nwpisz: ");
		scanf("%d", &num);
		// gracz wybiera opcje "graj"
		if (num == 1) {
			r = rand() % 3 + 1;
			//wyswietlenie instrukcji wybierania
			printf("tura\n1 - papier\n2 - kamien\n3 - nozyce\n:");
			scanf("%d", &num);
			// WYGRANA
			if (num == 1 && r == 2 || num == 2 && r == 3 || num == 3 && r == 1) {
				printf("Wygrana!\n");
				// tu przekazuje wynik do tablicy z wynikami
				// analogicznie w ponizszych ifach
				wyniki.s[wyniki.runda++] = 1;
			}
			// PRZEGRANA
			else if (num == 1 && r == 3 || num == 2 && r == 1 || num == 3 && r == 2) {
				printf("Przegrana!\n");
				wyniki.s[wyniki.runda++] = 2;
			}
			// REMIS
			else {
				printf("Remis!\n");
				wyniki.s[wyniki.runda++] = 3;
			}
		}
		// gracz wybiera opcje "wyswietl wyniki"
		else if (num == 2) {
			printf("wyniki\n");
			wyswietlWyniki(wyniki);
		}
	}
	wyswietlWyniki(wyniki);
	return 0;
}