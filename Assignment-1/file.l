%{
	#include <stdlib.h>
	#include "y.tab.h"
	void yyerror(char *);
	extern int line_number;
%}

 
%%

if                     	return IF;
else                  	return ELSE;
return                 	return RETURN;
while                   return WHILE;
do						return DO;
for						return FOR;
switch					return SWITCH;
case					return CASE;
default					return DEFAULT;
break					return BREAK;
continue				return CONTINUE;
extern 					return EXTERN;
sizeof					return SIZE_OF;

=						return EQ;
;						return EOL;

int                   	return INT;
long					return LONG;
short					return SHORT;	
float					return FLOAT;
double					return DOUBLE;
char					return CHAR;
void                    return VOID;
struct					return STRUCT;

"<="                   	return LESS_OR_EQUAL;                   
">="                  	return GREATER_OR_EQUAL;
"=="                    return EQUAL;
"!="                   	return NOT_EQUAL;
"++"					return INC_OP;
"--"					return DEC_OP;
 /* "+="					return ADD_ASSIGN;
"-="					return SUB_ASSIGN;
"*="					return MUL_ASSIGN;
"/="					return DIV_ASSIGN;*/
"<=>"					return THREE_WAY_OP;	
"&&"					return AND_OP;
"||"					return OR_OP;
"{"						return '{';
"}"						return '}';
","						return ',';
":"						return ':';
"("						return '(';
")"						return ')';
"["					    return '[';
"]"						return ']';
"."						return '.';
"&"						return '&';
"!"						return '!';
"~"						return '~';
"-"						return '-';
"+"						return '+';
"*"						return '*';
"/"						return '/';
"%"						return '%';
"<"						return '<';
">"						return '>';
"^"						return '^';
"|"						return '|';
"?"						return '?';


\"([^\"])*\"			return STRING;
\'([^\'])*\'			return STRING;

[a-zA-Z][_a-zA-Z0-9]*    {/*printf("%s",yytext);*/return ID;}

"0x"					return HEX;
[0-9][0-9]*				return INT_NUMBER;

\/\/(.*) 				;

\/\*([^*]*)\*\/			;

\/\*([^*]*[*][^\/][^*]*)*\*\/	;

\/\*					{yyerror("***lexing terminated*** [lexer error]: ill-formed comment");exit(1);}


[ \t]					;
[\n]					line_number++;				
.						{ //printf("Unknown symbol -> %s near line no:%d\n",yytext,line_number);
							yyerror("***parsing terminated*** [syntax error]");exit(1);
						}


%%

int yywrap(void) {
    return 1;
}


