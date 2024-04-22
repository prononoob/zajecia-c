#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int getFirstAndLastDigit(char* line) {
    bool foundFirstDigit = false;
    int firstDigit = 0, secondDigit = -1;
    while (*line != '\0') {
        // jesli cyfra i jeszcze nie znaleziono pierwszej cyfry
        if (*line >= '0' && *line <= '9' && !foundFirstDigit) {
            firstDigit = *line - '0';
            secondDigit = *line - '0';
            foundFirstDigit = true;
        }
        // jesli cyfra ale juz znaleziono pierwsza cyfre
        else if (*line >= '0' && *line <= '9' && foundFirstDigit) {
            secondDigit = *line - '0';
        }
        // jesli pierwsza litera wskazuje ze to moze byc cyfra napisana slownie
        else if (*line == 'o' || *line == 't' || *line == 'f' || *line == 's' || *line == 'e' || *line == 'n' || *line == 'z') {
            // przypisuje do drugiej cyfry wynik bo jesli nie znaleziono drugiej cyfry to zeby sie dublowala
            secondDigit = findDigits(&line, secondDigit);
            if (secondDigit >= 0 && !foundFirstDigit) {
                firstDigit = secondDigit;
                foundFirstDigit = true;
            }
        }
        line++;

    }
    int result = firstDigit * 10 + secondDigit;
    printf("WYNIK:\t%d\n", result);
    return result;
}

/* ta funkcja porownuje szukana slownie zapisana cyfre do kolejnych znakow
* na ktore wskazuje pointer linePtr
*/
bool compareDigitInString(char** linePtr, char* strToCheck) {
    int strLength = strlen(strToCheck);
    int i = 0;
    while (i < strLength) {
        if ((**linePtr) != strToCheck[i]) {
            (*linePtr)--;
            return false;
        }
        (*linePtr)++;
        i++;
    }
    (*linePtr)--;

    return true;
}
/*
* ta funkcja jest wolana jak jest jedna z liter ktora wskazuje ze to moze byc cyfra napisana slownie;
* pointer linePtr przechodzi po kolei po calej linijce, a linePtrTemporary jest tworzony jak jest mozliwe ze to cyfra, 
* zeby potem szybko mozna wrocic spowrotem do pozycji wczesniejszej litery na ktora ciagle wskazuje linePtr;
* potem w zaleznosci od litery porownuje litery po kolei, wolajac powyzsza funkcje i przypisuje odpowiedni wynik;
*/
int findDigits(char** linePtr, int defaultVal) {
    int result = defaultVal;
    char** linePtrTemporary = (char**)malloc(sizeof(char*));
    switch (**linePtr) {
    case 'o':
        (*linePtr)++;
        *linePtrTemporary = *linePtr;
        if (compareDigitInString(linePtrTemporary, "ne")) {
            // tutaj jesli znaleziono slowo to funkcja przesuwa linePtr na pozycje linePtrTemporary,
            // zeby nie przechodzic dwa razy przez to samo slowo
            *linePtr = *linePtrTemporary;
            result = 1;
        }
        else {
            (*linePtr)--;
        }
        break;
    case 't':
        (*linePtr)++;
        *linePtrTemporary = *linePtr;
        if (**linePtrTemporary == 'w' && compareDigitInString(linePtrTemporary, "wo")) {
            *linePtr = *linePtrTemporary;
            result = 2;
        }
        else if (**linePtrTemporary == 'h' && compareDigitInString(linePtrTemporary, "hree")) {
            *linePtr = *linePtrTemporary;
            result = 3;
        }
        else {
            (*linePtr)--;
        }
        break;
    case 'f':
        (*linePtr)++;
        *linePtrTemporary = *linePtr;
        if (**linePtrTemporary == 'o' && compareDigitInString(linePtrTemporary, "our")) {
            *linePtr = *linePtrTemporary;
            result = 4;
        }
        else if (**linePtrTemporary == 'i' && compareDigitInString(linePtrTemporary, "ive")) {
            *linePtr = *linePtrTemporary;
            result = 5;
        }
        else {
            (*linePtr)--;
        }
        break;
    case 's':
        (*linePtr)++;
        *linePtrTemporary = *linePtr;
        if (**linePtrTemporary == 'i' && compareDigitInString(linePtrTemporary, "ix")) {
            *linePtr = *linePtrTemporary;
            result = 6;
        }
        else if (**linePtrTemporary == 'e' && compareDigitInString(linePtrTemporary, "even")) {
            *linePtr = *linePtrTemporary;
            result = 7;
        }
        else {
            (*linePtr)--;
        }
        break;
    case 'e':
        (*linePtr)++;
        *linePtrTemporary = *linePtr;
        if (compareDigitInString(linePtrTemporary, "ight")) {
            *linePtr = *linePtrTemporary;
            result = 8;
        }
        else {
            (*linePtr)--;
        }
        break;
    case 'n':
        (*linePtr)++;
        *linePtrTemporary = *linePtr;
        if (compareDigitInString(linePtrTemporary, "ine")) {
            *linePtr = *linePtrTemporary;
            result = 9;
        }
        else {
            (*linePtr)--;
        }
        break;
    case 'z':
        (*linePtr)++;
        *linePtrTemporary = *linePtr;
        if (compareDigitInString(linePtrTemporary, "ero")) {
            *linePtr = *linePtrTemporary;
            result = 0;
        }
        else {
            (*linePtr)--;
        }
        break;
    }
    free(linePtrTemporary);
    return result;
}

int main() {
    /*
    * WYNIK Z 1 CZESCI TO 55971
    * WYNIK Z 2 CZESCI TO 54699
    */

    FILE* file = fopen("input1.txt", "r");

    // pusty plik
    if (file == NULL) {
        return 1;
    }

    char line[200];

    // czytam poki linijka nie jest NULL
    int result = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        result += getFirstAndLastDigit(line);
        //printf("%s", line);
    }

    fclose(file);
    printf("WYNIK KONCOWY \t%d\n", result);
	return 0;
}