%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	void yyerror(char *);
	int yylex(void);
	extern char *yytext;
	extern FILE * yyin;
	int global_dec=0;
	int func_def=0;
	int int_cons=0;
	int pnt_dec=0;
	int if_noelse=0;
	int ifelse_depth=0;
	
	int line_number=1;
	
	int error=0;
	int temp_depth=0;
	int in_if=0;

%}

%token IF ELSE RETURN DO WHILE FOR SWITCH BREAK CONTINUE EQ EOL EXTERN STRUCT CASE DEFAULT
%token INT LONG SHORT FLOAT DOUBLE CHAR VOID STRING SIZE_OF
%token LESS_OR_EQUAL GREATER_OR_EQUAL EQUAL NOT_EQUAL INC_OP DEC_OP 
%token AND_OP OR_OP THREE_WAY_OP
%token ID INT_NUMBER HEX
%left EQ
%left '+' '-' 
%left '*' '/'

%start program

%%

program:
	lines
;

lines:
	line 
|	line lines
;

line:
	var_dec  								{global_dec++;}
|	func_dec 								{global_dec++;}
|	struct_dec 								{global_dec++;}
|	var_struct  							{global_dec++;}
;

var_dec:
	mul_type assign_var EOL 					
;

var_assign:
	ID EOL 										
| 	ID array EOL
|	ID EQ expression EOL							
| 	ID array EQ expression EOL					
|	pointer ID EOL													
| 	pointer ID array EOL 			
|	pointer ID EQ expression EOL 					
| 	pointer ID array EQ expression EOL						
;

array:
	'[' num_ornot ']' 
|	'[' num_ornot ']' array
;

assign_var:
	ID  extend_var_dec 												
| 	ID array extend_var_dec								
|	ID EQ expression extend_var_dec									
| 	ID array EQ expression extend_var_dec				
|	pointer ID extend_var_dec									{pnt_dec++;}
| 	pointer ID array extend_var_dec 							{pnt_dec++;}
|	pointer ID EQ expression extend_var_dec 					{pnt_dec++;}
| 	pointer ID array EQ expression extend_var_dec 				{pnt_dec++;}					
;	

extend_var_dec:
	',' assign_var
|	%empty
;

func_dec:
	mul_type ID '(' args_ornot ')' EOL								
|	mul_type ID '(' args_ornot ')' '{' statements '}' 			
		{func_def++;}

|	mul_type pointer ID '(' args_ornot ')' EOL														
		{pnt_dec++;}

|	mul_type pointer ID '(' args_ornot ')' '{' statements '}'  		
		{pnt_dec++;func_def++;}	
|	STRUCT ID ID '(' args_ornot ')' EOL								
|	STRUCT ID ID '(' args_ornot ')' '{' statements '}' 			
		{func_def++;}

|	STRUCT ID pointer ID '(' args_ornot ')' EOL														
		{pnt_dec++;}

|	STRUCT ID pointer ID '(' args_ornot ')' '{' statements '}'  		
		{pnt_dec++;func_def++;}		
;

args_ornot:
	args_id
|	%empty
;

args_id:
	mul_type
|	mul_type ID
|	mul_type pointer
| 	mul_type pointer ID 											{pnt_dec++;}
|	mul_type ',' args_id
|	mul_type ID ',' args_id
|	mul_type pointer ',' args_id									
|	mul_type pointer ID ',' args_id									{pnt_dec++;}
|	mul_type array
|	mul_type ID array
|	mul_type pointer array
|	mul_type pointer ID array										{pnt_dec++;}
|	mul_type array ',' args_id
|	mul_type ID array ',' args_id
|	mul_type pointer array ',' args_id
|	mul_type pointer ID array ',' args_id							{pnt_dec++;}
;

statements:
	one_or_more_statement
|	%empty
;

one_or_more_statement:
	statement
|	statement one_or_more_statement
;

statement:
	var_dec
|	var_assign														
|	func_call EOL
|	struct_dec 														
|	var_struct
|	if_statement									
|	for_loop
|	while_loop
|	do_while
|	switch_statement
|	expression EOL
|	return_statement
|	CONTINUE EOL
|	BREAK EOL
|	EOL
;

func_call:
	ID '(' zeroormore_func_call_list ')'
;

zeroormore_func_call_list:
	func_call_list
|	%empty
;

func_call_list:
	expression 
|	expression ',' func_call_list
;

struct_dec:
	STRUCT ID '{' members '}' struct_names EOL 
;

members:
	struct_var 
|	struct_var members
|	var_struct
|	var_struct members
;

struct_var:
	mul_type struct_var_assign EOL
;

struct_var_assign:
	ID  extend_struct_var											
| 	ID array extend_struct_var
|	pointer ID extend_struct_var								{pnt_dec++;}						
| 	pointer ID array extend_struct_var 							{pnt_dec++;}		
;

extend_struct_var:
	',' struct_var_assign
|	%empty
;

struct_names:
	ID
| 	pointer ID													{pnt_dec++;}
|	ID ',' struct_names
|	pointer ID ',' struct_names									{pnt_dec++;}
|	ID array
|	pointer ID array											{pnt_dec++;}
|	ID array ',' struct_names					
|	pointer ID array ',' struct_names							{pnt_dec++;}
|	%empty
;

struct_assign:
	ID extend_struct_assign
|	ID EQ expression extend_struct_assign
| 	pointer ID extend_struct_assign								{pnt_dec++;}
| 	pointer ID EQ expression extend_struct_assign				{pnt_dec++;}
|	ID array extend_struct_assign
|	pointer ID array extend_struct_assign						{pnt_dec++;}
|	%empty
;

extend_struct_assign:
	',' struct_assign
|	%empty
;

var_struct:
	STRUCT ID struct_assign EOL
;

if_statement:
	IF '(' expression ')' '{' statements '}'					
			{if_noelse++;}

|	IF '(' expression ')' '{' statements '}' ELSE set_if_1 '{' statements '}' set_if_0 
			{if(in_if>0){temp_depth++;}}

|	IF '(' expression ')' '{' statements '}' ELSE set_if_1 statement set_if_0
|	IF '(' expression ')' statement ELSE set_if_1 '{' statements '}' set_if_0
|	IF '(' expression ')' statement ELSE set_if_1 statement set_if_0
|	IF '(' expression ')' statement 							
			{if_noelse++;}
;

set_if_1:
	%empty					{in_if+=1;if(ifelse_depth<in_if)ifelse_depth=in_if;}
;

set_if_0:
	%empty					{in_if-=1;}
;

for_loop:
	FOR '(' first_for num_ornot EOL num_ornot ')' '{' statements '}'
|	FOR '(' first_for num_ornot EOL num_ornot ')' statement
;

first_for:
	var_dec
|	assign_var EOL
|	EOL
;

while_loop:
	WHILE '(' expression ')' '{' statements '}'
|	WHILE '(' expression ')' statement
;

do_while:
	DO '{' statements '}' WHILE '(' expression ')' EOL
|	DO statement WHILE '(' expression ')' EOL
;

switch_statement:
	SWITCH '(' expression ')' '{' case_statement '}' 
;

case_statement:
	CASE expression ':' statements case_statement
|	CASE expression ':' statements BREAK EOL case_statement
|	DEFAULT ':' statements 
|	DEFAULT ':' statements BREAK EOL
|	%empty
;	

return_statement:
	RETURN num_ornot EOL
;

pointer:
	'*'	
| 	'*' pointer
;

expression:
	'(' expression ')'
|	conditional_expr
|	un_op expression
|	size_of
|	'*' expression
|	typecast expression
|	operational_expr
|	expression '[' expression ']'
|	func_call
|	number
|	string
|	ID
;

conditional_expr:
	expression cond_op expression
|	'(' conditional_expr ')'	
;

string:
	STRING
|	STRING string
;

cond_op:
	LESS_OR_EQUAL 
|	GREATER_OR_EQUAL 
|	EQUAL 
|	NOT_EQUAL 
|	AND_OP
|	OR_OP
|	THREE_WAY_OP
|	'<'
|	'>'
;

un_op:
	'+'
|	'-'
|	'&'
|	'~'
|	'!'
;

operational_expr:
	expression bin_op expression 
|	expression INC_OP
|	INC_OP expression
|	expression DEC_OP
|	DEC_OP expression
;

bin_op:
	'+'
|	'-'
|	'*'
|	'/'
|	'&'
|	'|'
|	'%'
|	'^'
|	'.'
|	'-' '>'
|	EQ 
;

num_ornot:
	expression
|	%empty
;

size_of:
	SIZE_OF '(' mul_type ')'
|	SIZE_OF '(' mul_type pointer ')'
;

typecast:
	'(' mul_type ')'
|	'(' mul_type pointer ')'
;

mul_type:
	STRUCT ID
|	type 				
|	type mul_type 
|	STRUCT ID mul_type	
;

type:
	INT 	
| 	LONG	
| 	SHORT	
| 	FLOAT
| 	DOUBLE
| 	CHAR  
| 	VOID 	
|	EXTERN 
;

number:
	INT_NUMBER			{int_cons++;}
|	'.'	INT_NUMBER
|	INT_NUMBER '.' INT_NUMBER
|	HEX	INT_NUMBER		{int_cons++;}
;

%%

void yyerror(char *s) {
	error=1;
    //printf("ERROR:- %s near line no: %d, last token read is: %s\n",s,line_number,pres);
    if(strcmp(s,"syntax error")==0){
    	printf("***parsing terminated*** [syntax error]\n");
    }
    else{
    	printf("%s\n", s);
    }
}

int main(int argc,char* argv[]){
	if(argc != 2){
	   	printf("***process terminated*** [input error]: invalid number of command-line argumnets\n");
		return 0;
    }
    FILE *file_open = fopen( argv[1] , "r" );
    if (!file_open) {
		printf("***process terminated*** [input error]: no such file %s exists\n",argv[1]);
		return 0;
    } 
    yyin = file_open;
	yyparse();
   	if(error==0){
	    printf("***parsing successful***\n");
		printf("#global_declarations = %d\n",global_dec);
		printf("#function_definitions = %d\n",func_def);
		printf("#integer_constants = %d\n",int_cons);
		printf("#pointers_declarations = %d\n",pnt_dec);
		printf("#ifs_without_else = %d\n",if_noelse);
		printf("if-else max-depth = %d\n",ifelse_depth);
	}
	fclose(file_open);
    return 0;
}

