#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int* readGames(char* line) {
    int* returnValues = malloc(2 * sizeof(int));
    // wyciaganie numeru gry
    int gameID = 0;

    while (*line != ' ') {
        line++;
    }
    line++;
    while (*line != ':') {
        gameID = gameID * 10 + *line - 48;
        line++;
    }
    printf("%d\n", gameID);
    
    // maksymalne ilosci kolejnych kosci
    int r = 12, g = 13, b = 14;
    // minimalne ilosci kolejnych kosci
    int minValsRGB[3] = { 0, 0, 0 };
    int numOfDices = 0;
    bool isPossible = true;

    // porownywanie ilosci kosci do maksymalnej ilosci kosci tego koloru
    while (*line != '\0') {
        while (!isdigit(*line)) {
            if (*line == '\0') {
                break;
            }
            line++;
        }
        if (*line == '\0') {
            break;
        }
        numOfDices = 0;
        char colorOfDice;
        while (isdigit(*line) && *line != '\0') {
            numOfDices = numOfDices * 10 + *line - 48;
            line++;
        }
        line += 1;
        colorOfDice = *line;
        // czy ilosc kosci wykracza poza maksimum dla tego koloru
        if (colorOfDice == 'r' && numOfDices > r || colorOfDice == 'g' && numOfDices > g || colorOfDice == 'b' && numOfDices > b) {
            isPossible = false;

        }
        switch (colorOfDice)
        {
        case 'r':
            if (numOfDices > minValsRGB[0]) {
                minValsRGB[0] = numOfDices;
            }
            break;
        case 'g':
            if (numOfDices > minValsRGB[1]) {
                minValsRGB[1] = numOfDices;
            }
            break;
        case 'b':
            if (numOfDices > minValsRGB[2]) {
                minValsRGB[2] = numOfDices;

                break;
            }
        default:
            break;
        }
        printf("%d - %c, ", numOfDices, colorOfDice);
        line++;
    }
    if (!isPossible) {
        printf("\nGra %d jest niemozliwa", gameID);
    }
    printf("\n%d\n", minValsRGB[0] * minValsRGB[1] * minValsRGB[2]);
    printf("\n");
    returnValues[0] = gameID;
    returnValues[1] = minValsRGB[0] * minValsRGB[1] * minValsRGB[2];
    return returnValues;
}

int main() {
    FILE* file = fopen("input2.txt", "r");

    // pusty plik
    if (file == NULL) {
        return 1;
    }

    char line[200];

    // czytam poki linijka nie jest NULL
    int gameIDsum = 0, mocKosciSum = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        int* results = readGames(line);
        gameIDsum += results[0];
        mocKosciSum += results[1];
        free(results);
        //printf("%s", line);
    }
    printf("Suma identyfikatorow gier: %d\nSuma mocy zestawow kosci: %d", gameIDsum, mocKosciSum);

    fclose(file);
	return 0;
}