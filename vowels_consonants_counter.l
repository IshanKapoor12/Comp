%{
#include <stdio.h>

int vowelCount = 0;
int consonantCount = 0;
%}

%%
[aAeEiIoOuU]    { vowelCount++; }
[a-zA-Z]       { consonantCount++; }
\n {return 0;}
.              { /* Ignore other characters */ }
%%

int main() {
    yylex();
    printf("Vowel count: %d\n", vowelCount);
    printf("Consonant count: %d\n", consonantCount);
    return 0;
}
int yywrap(){
return 1;
}


