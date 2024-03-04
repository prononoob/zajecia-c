#include <stdlib.h>
#include <stdio.h>
#define MAX_KONTAKTOW 25

struct Contact {
	char imie[25];
	char nazwisko[25];
	char nrTel[12];
};

struct Contact ksiazka[MAX_KONTAKTOW];
int liczbaKontaktow = 0;

void dodajKontakt(struct Contact nowyKontakt) {
    if (liczbaKontaktow < MAX_KONTAKTOW) {
        ksiazka[liczbaKontaktow++] = nowyKontakt;
        printf("Kontakt dodany pomyslnie.\n");
    }
    else {
        printf("Ksiazka adresowa pelna. Nie mozna dodac nowego kontaktu.\n");
    }
}

void wyszukajPoNazwisku(char* nazwisko) {
    int znaleziono = 0;
    for (int i = 0; i < liczbaKontaktow; ++i) {
        if (strcmp(ksiazka[i].nazwisko, nazwisko) == 0) {
            printf("\nZnaleziono kontakt:\n");
            printf("Imie: %s\n", ksiazka[i].imie);
            printf("Nazwisko: %s\n", ksiazka[i].nazwisko);
            printf("Nr. telefonu: %s\n", ksiazka[i].nrTel);
            znaleziono = 1;
        }
    }
    if (!znaleziono) {
        printf("Nie znaleziono kontaktu o nazwisku %s.\n", nazwisko);
    }
}

void usunKontakt(char* nazwisko) {
    int found = 0;
    for (int i = 0; i < liczbaKontaktow; i++) {
        if (strcmp(ksiazka[i].nazwisko, nazwisko) == 0) {
            for (int j = i; j < liczbaKontaktow - 1; j++) {
                ksiazka[j] = ksiazka[j + 1];
            }
            liczbaKontaktow--;
            printf("Kontakt zostal usuniety.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Nie znaleziono kontaktu o nazwisku %s.\n", nazwisko);
    }
}

void wypiszWszystkieKontakty() {
    printf("Wszystkie kontakty w ksiazce adresowej:\n");
    for (int i = 0; i < liczbaKontaktow; i++) {
        printf("\nKontakt %d:\n", i + 1);
        printf("Imie: %s\n", ksiazka[i].imie);
        printf("Nazwisko: %s\n", ksiazka[i].nazwisko);
        printf("Numer telefonu: %s\n", ksiazka[i].nrTel);
    }
}

int main() {
    dodajKontakt((struct Contact) { "Jan", "Kowalski", "123456789" });
    dodajKontakt((struct Contact) { "Anna", "Nowak", "987654321" });
    dodajKontakt((struct Contact) { "Piotr", "Nowakowski", "555444333" });
    dodajKontakt((struct Contact) { "Ewa", "Wisniewska", "111222333" });
    dodajKontakt((struct Contact) { "Adam", "Nowak", "777888999" });
    wyszukajPoNazwisku("Nowak");
    usunKontakt("Nowakowski");
    wypiszWszystkieKontakty();
	return 0;
}