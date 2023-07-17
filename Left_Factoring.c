#include <stdio.h>
#include <string.h>

void eliminateLeftFactoring(char nonTerminal[], char productions[][100], int numProductions) {
    int i, j, k;
    int flag = 0;
    char newNonTerminal[100];
    int len = strlen(productions[0]);

    for (i = 0; i < len; i++) {
        if (flag == 1 || productions[0][i] != productions[1][i]) {
            flag = 1;
            newNonTerminal[i] = productions[0][i];
        } else {
            newNonTerminal[i] = ' ';
        }
    }

    newNonTerminal[i] = '\0';

    printf("New Non-Terminal: %s\n", newNonTerminal);

    printf("%s -> ", nonTerminal);
    printf("%s', ", newNonTerminal);
    printf("%s'\n", nonTerminal);

    printf("%s' -> ", newNonTerminal);

    for (i = 0; i < numProductions; i++) {
        if (strncmp(productions[i], productions[0], strlen(newNonTerminal)) != 0) {
            printf("%s | ", productions[i]);
        }
    }

    printf("\u03B5\n");
}

int main() {
    char nonTerminal[100];
    char productions[10][100];
    int numProductions;

    printf("Enter the non-terminal: ");
    scanf("%s", nonTerminal);

    printf("Enter the number of productions: ");
    scanf("%d", &numProductions);

    printf("Enter the productions:\n");
    for (int i = 0; i < numProductions; i++) {
        scanf("%s", productions[i]);
    }

    eliminateLeftFactoring(nonTerminal, productions, numProductions);

    return 0;
}

