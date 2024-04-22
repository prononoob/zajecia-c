#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int getFirstAndLastDigit(char* line) {
    bool foundFirstDigit = false;
    int firstDigit = 0, secondDigit = -1;
    while (*line != '\0') {
        if (*line >= '0' && *line <= '9' && !foundFirstDigit) {
            firstDigit = *line - '0';
            secondDigit = *line - '0';
            foundFirstDigit = true;
        }
        else if (*line >= '0' && *line <= '9' && foundFirstDigit) {
            secondDigit = *line - '0';
        }
        else if (*line == 'o' || *line == 't' || *line == 'f' || *line == 's' || *line == 'e' || *line == 'n' || *line == 'z') {
            //printf("\tFD%d\tSD: %d\n", firstDigit, secondDigit);
            secondDigit = findDigits(&line, secondDigit);
            if (secondDigit >= 0 && !foundFirstDigit) {
                firstDigit = secondDigit;
                foundFirstDigit = true;
            }
            //printf("\tFD%d\tSD: %d\n", firstDigit, secondDigit);
        }

        //printf("FD%d\tSD: %d\n", firstDigit, secondDigit);
        line++;

    }
    //printf("%d\t%d\n", firstDigit, secondDigit);
    int result = firstDigit * 10 + secondDigit;
    printf("WYNIK:\t%d\n", result);
    return result;
}

bool compareDigitInString(char** linePtr, char* strToCheck) {
    int strLength = strlen(strToCheck);
    int i = 0;
    while (i < strLength) {
        //printf("%c %c\n", (**linePtr), strToCheck[i]);
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

int findDigits(char** linePtr, int defaultVal) {
    int result = defaultVal;
    char** linePtrTemporary = (char**)malloc(sizeof(char*));
    switch (**linePtr) {
    case 'o':
        (*linePtr)++;
        *linePtrTemporary = *linePtr;
        if (compareDigitInString(linePtrTemporary, "ne")) {
            *linePtr = *linePtrTemporary;
            result = 1;
        }
        else {
            (*linePtr)--;
        }
        break;
    case 't':
        // Code for case 2
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
        // Code for case 3
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
        // Code for case 4
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
        // Code for case 5
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
        // Code for case 6
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
        // Code for case 7
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
    * TWOJ WYNIK Z 1 CZESCI TO 55971
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