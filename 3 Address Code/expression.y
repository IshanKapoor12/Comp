%{
#include <stdio.h>
#include <stdlib.h>
extern char* yytext;
extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}

int yylex();
%}

%token ID NUM

%left '+' '-'
%left '*' '/'

%%
program : ID '=' expression { printf("%s = %s\n", $1, $3); }
        ;

expression : term { $$ = $1; }
           | expression '+' term { $$ = create_temp(); emit($$, $1, $3, "+"); }
           | expression '-' term { $$ = create_temp(); emit($$, $1, $3, "-"); }
           ;

term : factor { $$ = $1; }
     | term '' factor { $$ = create_temp(); emit($$, $1, $3, ""); }
     | term '/' factor { $$ = create_temp(); emit($$, $1, $3, "/"); }
     ;

factor : ID { $$ = $1; }
       | NUM { $$ = create_const($1); }
       | '(' expression ')' { $$ = $2; }
       ;

%%

int main() {
    yyin = stdin;
    return yyparse();
}

int create_temp() {
    static int count = 1;
    char temp[10];
    sprintf(temp, "T%d", count++);
    return strdup(temp);
}

int create_const(int value) {
    char temp[10];
    sprintf(temp, "%d", value);
    return strdup(temp);
}

void emit(const char* result, const char* arg1, const char* arg2, const char* op) {
    printf("%s = %s %s %s\n", result, arg1, op, arg2);
}
