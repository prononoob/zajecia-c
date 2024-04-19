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
    switch (**linePtr) {
    case 'o':
        (*linePtr)++;
        if (compareDigitInString(linePtr, "ne")) {
            result = 1;
        }
        break;
    case 't':
        // Code for case 2
        (*linePtr)++;
        if (**linePtr == 'w') {
            compareDigitInString(linePtr, "wo");
        }
        else if (**linePtr == 'h') {
            compareDigitInString(linePtr, "hree");
        }
        else {
            (*linePtr)--;
        }
        break;
    case 'f':
        // Code for case 3
        //printf("You chose option 3\n");
        break;
    case 's':
        // Code for case 4
        //printf("You chose option 4\n");
        break;
    case 'e':
        // Code for case 5
        //printf("You chose option 5\n");
        break;
    case 'n':
        // Code for case 6
        //printf("You chose option 6\n");
        break;
    case 'z':
        // Code for case 7
        //printf("You chose option 7\n");
        break;
    }
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
        // printf("%s", line);
    }

    fclose(file);
    printf("WYNIK KONCOWY \t%d\n", result);
	return 0;
}