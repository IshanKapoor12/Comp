#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_RULES 10
#define MAX_SYMBOLS 10

typedef struct {
    char nonTerminal;
    char production[MAX_SYMBOLS];
} Rule;

bool isNonTerminal(char symbol) {
    return (symbol >= 'A' && symbol <= 'Z');
}

void eliminateLeftRecursion(Rule rules[], int numRules, char nonTerminal) {
    int i, j;
    int numNewRules = 0;
    Rule newRules[MAX_RULES];

    for (i = 0; i < numRules; i++) {
        if (rules[i].nonTerminal == nonTerminal) {
            if (rules[i].production[0] == nonTerminal) {
                // Rule with left recursion detected

                // Create a new non-terminal symbol
                char newNonTerminal = nonTerminal; // Convert to lowercase

                // Create new rules to eliminate left recursion
                newRules[numNewRules].nonTerminal = newNonTerminal;
                strcpy(newRules[numNewRules].production, &rules[i].production[1]);
                strcat(newRules[numNewRules].production, &newNonTerminal);
                numNewRules++;

                for (j = 0; j < numRules; j++) {
                    if (rules[j].nonTerminal == nonTerminal && rules[j].production[0] != nonTerminal) {
                        // Copy original rule and append the new non-terminal symbol
                        newRules[numNewRules].nonTerminal = nonTerminal;
                        strcpy(newRules[numNewRules].production, rules[j].production);
                        strcat(newRules[numNewRules].production, &newNonTerminal);
                        numNewRules++;
                    }
                }
            } else {
                // Rule without left recursion
                newRules[numNewRules] = rules[i];
                numNewRules++;
            }
        }
    }

    // Remove the original non-terminal rules
    for (i = 0; i < numRules; i++) {
        if (rules[i].nonTerminal == nonTerminal) {
            numRules--;
            for (j = i; j < numRules; j++) {
                rules[j] = rules[j + 1];
            }
            i--;
        }
    }

    // Update the original rules array with new rules
    for (i = 0; i < numNewRules; i++) {
        rules[numRules + i] = newRules[i];
    }
}

int main() {
    Rule rules[MAX_RULES];
    int numRules = 0;
    int i;

    printf("Enter the number of rules: ");
    scanf("%d", &numRules);

    printf("Enter the rules in the form 'A -> alpha':\n");
    for (i = 0; i < numRules; i++) {
        scanf(" %c -> %s", &rules[i].nonTerminal, rules[i].production);
    }

    for (i = 0; i < numRules; i++) {
        if (isNonTerminal(rules[i].nonTerminal)) {
            eliminateLeftRecursion(rules, numRules, rules[i].nonTerminal);
        }
    }

    printf("\nModified Rules:\n");
    for (i = 0; i < numRules; i++) {
        printf("%c' -> %s'\n", rules[i].nonTerminal, rules[i].production);
    }

    return 0;
}

