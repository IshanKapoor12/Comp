#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 100

// Function to check if a character is a valid identifier character
int isValidIdentifierChar(char ch) {
    return isalnum(ch) || ch == '_';
}

// Function to tokenize a string
void tokenizeString(const char* input) {
    int length = strlen(input);
    char token[MAX_TOKEN_LENGTH];

    int i = 0;
    while (i < length) {
        // Skip whitespace characters
        while (i < length && isspace(input[i])) {
            i++;
        }

        // Check for operators
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '=' || input[i] == '--' || input[i] == '%') {
            printf("Operator: %c\n", input[i]);
            i++;
        }
        // Check for punctuation
        else if (input[i] == '(' || input[i] == ')' || input[i] == '{' || input[i] == '}' || input[i] == ',' || input[i] == ';' || input[i] == '"') {
            printf("Punctuation: %c\n", input[i]);
            i++;
        }
        // Check for constants
        else if (isdigit(input[i])) {
            int j = 0;
            while (i < length && isdigit(input[i])) {
                token[j++] = input[i++];
            }
            token[j] = '\0';
            printf("Constant: %s\n", token);
        }
        // Check for identifiers or keywords
        else if (isalpha(input[i]) || input[i] == '_') {
            int j = 0;
            while (i < length && isValidIdentifierChar(input[i])) {
                token[j++] = input[i++];
            }
            token[j] = '\0';

            if (strcmp(token, "if") == 0 || strcmp(token, "else") == 0 || strcmp(token, "while") == 0 || strcmp(token, "for") == 0 || strcmp(token, "int") == 0) {
                printf("Keyword: %s\n", token);
            } else {
                printf("Identifier: %s\n", token);
            }
        }
        
        int isConstant(const char* token) {
    		int length = strlen(token);
    		for (int i = 0; i < length; i++) {
        		if (!isdigit(token[i])) {
            		return 0;
        		}
    		}

   			return 1;
		}
        // Invalid token
        else {
            printf("Invalid token: %c\n", input[i]);
            i++;
        }
    }
}

int main() {
    const char* input = "int main() { int x = 5; while (x > 0) { printf(\"x = %d\\n\", x); x--; } return 0; }";
    tokenizeString(input);

    return 0;
}

