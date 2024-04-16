#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int getFirstAndLastDigit(char* line) {
    bool foundFirstDigit = false;
    int firstDigit = 0, secondDigit = 0;
    while (*line != '\0') {
        if (*line >= '0' && *line <= '9' && !foundFirstDigit) {
            firstDigit = *line - '0';
            secondDigit = *line - '0';
            foundFirstDigit = true;
        }
        else if (*line >= '0' && *line <= '9' && foundFirstDigit) {
            secondDigit = *line - '0';
        }
        // here code but dont write it pls
        else if (*line == 'o' || *line == 't' || *line == 'f' || *line == 's' || *line == 'e' || *line == 'n' || *line == 'z') {
            secondDigit = findDigits(&line, secondDigit);
        }

        line++;

    }
    printf("%d%d\n", firstDigit, secondDigit);
    int result = firstDigit * 10 + secondDigit;
    printf("%d\n", result);
    return result;
}

int findDigits(char** linePtr, int defaultVal) {
    int result = defaultVal;
    switch (**linePtr) {
    case 'o':
        // Code for case 1
        printf("You chose option 1\n");
        break;
    case 't':
        // Code for case 2
        printf("You chose option 2\n");
        break;
    case 'f':
        // Code for case 3
        printf("You chose option 3\n");
        break;
    case 's':
        // Code for case 4
        printf("You chose option 4\n");
        break;
    case 'e':
        // Code for case 5
        printf("You chose option 5\n");
        break;
    case 'n':
        // Code for case 6
        printf("You chose option 6\n");
        break;
    case 't':
        // Code for case 7
        printf("You chose option 7\n");
        break;
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
    printf("%d\n", result);
	return 0;
}