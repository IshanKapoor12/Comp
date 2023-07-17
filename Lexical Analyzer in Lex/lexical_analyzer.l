%%

#.* 											{printf("Pre-processor directive: %s\n\n",yytext);}
[''|,|;(|)|{|}|.|_] 									{printf("Delimiter: %s\n",yytext);}
[[]] 											{printf("Delimiter: %s\n",yytext);}
"<="|">="|"++"|"!="|"=="|"<"|">"  							{printf("Operator: %s\n",yytext);}
"+"|"-"|"*"|"/"  									{printf("Operator: %s\n",yytext);}
"and"|"or"|"not"|"nand"|"xor"|"nor"|"xnor"  						{printf("Operator: %s\n",yytext);}
"&"|"|"|"!"|"^" 						                        {printf("Operator: %s\n",yytext);}		
"=" 				 				                        {printf("Operator: %s\n",yytext);}
("int")|("if")|("else")|("while")|("do")|("break")|("continue")|("double")|("float")|("return")|("EOF") {printf("Keyword: %s\n",yytext);}
("return")|("char")|("case")|("sizeof")|("long")|("short")|("typedef")|("switch")|("unsigned")|("void")|("static")|("struct")|("goto") {printf("Keyword:%s\n",yytext);}
[a-zA-Z_$][a-zA-Z0-9_$]* 								{printf("Identifier: %s\n",yytext);}
[-]?[0-9]+"."[0-9]+ 									{printf("Constant : %s\n", yytext);} 
[-]?[0-9]+ 										{printf("Constant: %s\n",yytext);}
["][^"\\\n]*["]	 									{printf("String constant:%s\n",yytext);}
[ ]                                                             			{;}
[\t\n]+
. 											{printf("Not recognized: %s\n",yytext);}

%%

#include <stdio.h>

extern int yylex();
extern char* yytext;

int main(){
    yylex();
	return 0;

}

int yywrap(void) {
    return 1;
}


