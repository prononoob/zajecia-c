#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

void readGames(char* line) {
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
    int numOfDices = 0;

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
        bool isPossible = true;
        switch (colorOfDice)
        {
        case 'r':
            if (numOfDices > r) {
                printf("\nGra %d jest niemozliwa, za duzo czerwonych kosci", gameID);
                isPossible = false;
                break;
            }
        case 'g':
            if (numOfDices > g) {
                printf("\nGra %d jest niemozliwa, za duzo zielonych kosci", gameID);
                isPossible = false;
                break;
            }
        case 'b':
            if (numOfDices > b) {
                printf("\nGra %d jest niemozliwa, za duzo niebieskich kosci", gameID);
                isPossible = false;
                break;
            }
        default:
            break;
        }
        if (!isPossible) {
            break;
        }
        printf("%d - %c, ", numOfDices, colorOfDice);
        line++;
    }
    printf("\n\n");
}

int main() {
    FILE* file = fopen("input2.txt", "r");

    // pusty plik
    if (file == NULL) {
        return 1;
    }

    char line[200];

    // czytam poki linijka nie jest NULL
    int result = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        readGames(line);
        //printf("%s", line);
    }

    fclose(file);
	return 0;
}