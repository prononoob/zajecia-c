#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int getFirstAndLastDigit(char* line) {
    bool foundFirstDigit = false;
    int firstDigit = 0, secondDigit = 0;
    while (*line != '\0') {
        if (*line >= '0' && *line <= '9' && !foundFirstDigit) {
            firstDigit = *line - '0';
            foundFirstDigit = true;
        }
        else if (*line >= '0' && *line <= '9' && foundFirstDigit) {
            secondDigit = *line - '0';
        }

        line++;

    }
    //printf("%d%d\n", firstDigit, secondDigit);
    int result = firstDigit * 10 + secondDigit;
    printf("%d\n", result);
    return result;
}

int main() {
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

    fclose(file); // Close the file
    printf("%d\n", result);
	return 0;
}