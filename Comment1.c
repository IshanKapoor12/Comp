#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isComment(const char *line) {
    // Check for single-line comment
    if (strncmp(line, "//", 2) == 0) {
        return true;
    }

    // Check for multi-line comment
    if (strncmp(line, "/*", 2) == 0) {
        return true;
    }

    return false;
}
int main() {
    char line[100];

    // Read the line from input
    printf("Enter a line: ");
    fgets(line, sizeof(line), stdin);

    // Remove the newline character at the end
    line[strcspn(line, "\n")] = '\0';

    // Check if the line is a comment
    if (isComment(line)) {
        printf("The line is a comment.\n");
    } else {
        printf("The line is not a comment.\n");
    }

    return 0;
}



