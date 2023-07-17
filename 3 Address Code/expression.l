%{
#include "y.tab.h"
%}

%%

[a-zA-Z][a-zA-Z0-9]*    yylval = strdup(yytext); return ID;
[0-9]+                  yylval = atoi(yytext); return NUM;
[ \t]                   ; // Skip whitespace
.                       return yytext[0];

%%

int yywrap() {
    return 1;
}
