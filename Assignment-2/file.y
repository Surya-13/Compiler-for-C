%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	typedef struct container{
		int len;
		int val;
	}container;
	typedef struct Node{
		container node;
		int sz;
		struct Node* children[10];
	}Node;
	void yyerror(char *);
	int yylex(void);
	extern char *yytext;
	int in_main=0;
	int line_number=1;
	char temp[100];
	int long_all=0;
	int long_if=0;
	int long_while=0;
	int long_switch=0;
	int long_main=0;
	int error=0;
	int max(int i,int j){
		if(i<j)return j;
		return i;
	}
	void update(Node* root){
		if(root->sz==0)return;
		if(root->sz==1){
			long_all = max(long_all,root->children[0]->node.len+1);
			root->node.len = root->children[0]->node.len+1;
			root->node.val = max(root->node.val,root->children[0]->node.len+1);
		}
		else{
			int max1=-1;
			int max2=-1;
			for(int i=0;i<root->sz;i++){
				if(max1<root->children[i]->node.len){
					max2=max1;
					max1=root->children[i]->node.len;
				}
				else if(max2<root->children[i]->node.len){
					max2=root->children[i]->node.len;
				}
				root->node.val = max(root->node.val,root->children[i]->node.val);
			}
			long_all = max(max1+max2+1,long_all);
			root->node.len=max1+1;
			root->node.val = max(root->node.val,max1+max2+1);
		}
	}
	void evt1(Node *root,Node *c1){
		root->children[0]=c1;
		root->sz=1;
		update(root);
	}
	void evt2(Node *root,Node *c1,Node *c2){
		root->children[0]=c1;
		root->children[1]=c2;
		root->sz=2;
		update(root);
	}
	void evt3(Node *root,Node *c1,Node *c2,Node *c3){
		//printf("eval3 %d,%d,%d\n",c1->node.len,c2->node.len,c3->node.len);
		root->children[0]=c1;
		root->children[1]=c2;
		root->children[2]=c3;
		root->sz=3;
		update(root);
	}
	void evt4(Node *root,Node *c1,Node *c2,Node *c3,Node* c4){
		//printf("eval4 %d,%d,%d,%d",c1->node.len,c2->node.len,c3->node.len,c4->node.len);
		root->children[0]=c1;
		root->children[1]=c2;
		root->children[2]=c3;
		root->children[3]=c4;
		root->sz=4;
		update(root);
	}
	#define YYSTYPE Node
%}

%token IF ELSE RETURN DO WHILE FOR SWITCH BREAK CONTINUE EQ EOL EXTERN STRUCT CASE DEFAULT
%token INT LONG SHORT FLOAT DOUBLE CHAR VOID STRING SIZE_OF
%token LESS_OR_EQUAL GREATER_OR_EQUAL EQUAL NOT_EQUAL INC_OP DEC_OP 
%token AND_OP OR_OP THREE_WAY_OP PRINTF ARROW FORMAT_SPEC
%token ID INT_NUMBER HEX 

%start program


%%
program:										
	decl_list								{evt1(&$$,&$1);}							
;
decl_list:									
	decl  									{evt1(&$$,&$1);}	
|	decl_list decl							{evt2(&$$,&$1,&$2);}	
;
decl:
	var_decl								{evt1(&$$,&$1);}//printf("var %d len = %d\n",long_all,$1.node.len);}	
|	func_decl								{evt1(&$$,&$1);}//printf("fun %d len = %d\n",long_all,$1.node.len);}
|	struct_decl          					{evt1(&$$,&$1);}//printf("struct %d len = %d\n",long_all,$1.node.len);}
;
struct_decl:
	STRUCT identifier '{' local_decs '}' EOL	{evt2(&$$,&$2,&$4);}
;
var_decl:
	type_spec identifier EOL								{evt2(&$$,&$1,&$2);}
|	type_spec identifier ',' var_decl						{evt3(&$$,&$1,&$2,&$4);}
|	type_spec identifier '[' integerLit ']' EOL 			{evt3(&$$,&$1,&$2,&$4);}
|	type_spec identifier '[' integerLit ']' ',' var_decl	{evt4(&$$,&$1,&$2,&$4,&$7);}
;
type_spec:
	extern_spec VOID 						{evt1(&$$,&$1);}
|	extern_spec INT 						{evt1(&$$,&$1);}
|	extern_spec FLOAT  						{evt1(&$$,&$1);}
|	extern_spec VOID '*'    				{evt1(&$$,&$1);}
|	extern_spec INT '*' 					{evt1(&$$,&$1);}
|	extern_spec FLOAT '*' 					{evt1(&$$,&$1);}
|	STRUCT identifier 						{evt1(&$$,&$2);}
|	STRUCT identifier '*'   				{evt1(&$$,&$2);}
;
extern_spec:
	EXTERN 									{$$.node = (container){2,2};$$.sz=1;}
|	%empty									{$$.node = (container){2,2};$$.sz=1;}
;
func_decl:
	type_spec identifier '(' params ')' compound_stmt 		
		{evt4(&$$,&$1,&$2,&$4,&$6);if(in_main){long_main=max(long_main,$$.node.val);in_main-=1;}}
;
params:
	param_list 								{evt1(&$$,&$1);}
|	%empty 									{$$.node = (container){2,2};$$.sz=1;}	
;
param_list:
	param 									{evt1(&$$,&$1);}
|	param_list ',' param					{evt2(&$$,&$1,&$3);}
;
param:
	type_spec identifier					{evt2(&$$,&$1,&$2);}
|	type_spec identifier '[' ']'			{evt2(&$$,&$1,&$2);}
;
stmt_list:
	stmt 									{evt1(&$$,&$1);}
|	stmt_list stmt							{evt2(&$$,&$1,&$2);}//printf("stat %d,%d\n",$1.node.len,$2.node.len);}
;
stmt:
	assign_stmt								{evt1(&$$,&$1);}
|	compound_stmt							{evt1(&$$,&$1);}
|	if_stmt									{evt1(&$$,&$1);}
|	while_stmt								{evt1(&$$,&$1);}
|	switch_stmt								{evt1(&$$,&$1);}
|	return_stmt								{evt1(&$$,&$1);}
|	break_stmt								{evt1(&$$,&$1);}
|	continue_stmt							{evt1(&$$,&$1);}
|	dowhile_stmt							{evt1(&$$,&$1);}
|	print_stmt								{evt1(&$$,&$1);}
|	incr_stmt								{evt1(&$$,&$1);}
|	decr_stmt								{evt1(&$$,&$1);}
;
while_stmt:
	WHILE '(' expr ')' stmt 
					{evt2(&$$,&$3,&$5);long_while=max(long_while,$$.node.val);}
;
dowhile_stmt:
	DO stmt WHILE '(' expr ')' EOL   		{evt2(&$$,&$2,&$5);}
;
print_stmt:
	PRINTF '(' format_specifier ',' identifier ')' EOL		{evt2(&$$,&$3,&$5);}
;
format_specifier:
	FORMAT_SPEC 							{$$.node = (container){2,2};$$.sz=1;}
;
compound_stmt:
	'{' local_decs stmt_list '}'			{evt2(&$$,&$2,&$3);}//printf("comp %d,%d\n",$2.node.len,$3.node.len);}
;
local_decs:
	local_decl local_decs					{evt2(&$$,&$1,&$2);}//printf("loc %d,%d\n",$1.node.len,$2.node.len);}
|	%empty									{$$.node = (container){2,2};$$.sz=1;}
;
local_decl:	
	type_spec identifier EOL					{evt2(&$$,&$1,&$2);}
|	type_spec identifier '[' expr ']' EOL		{evt3(&$$,&$1,&$2,&$4);}	
;
if_stmt:
	IF '(' expr ')' stmt 					{evt2(&$$,&$3,&$5);long_if=max(long_if,$$.node.val);}//printf("if-len = %d\n",long_if);}
|	IF '(' expr ')' stmt ELSE stmt 			{evt3(&$$,&$3,&$5,&$7);long_if=max(long_if,$$.node.val);}
;
return_stmt:
	RETURN EOL								{$$.node = (container){2,2};$$.sz=1;}
|	RETURN expr EOL							{evt1(&$$,&$2);}
;
break_stmt:
	BREAK EOL								{$$.node = (container){2,2};$$.sz=1;}
;
continue_stmt:
	CONTINUE EOL							{$$.node = (container){2,2};$$.sz=1;}
;
switch_stmt:
	SWITCH '(' expr ')' '{' compound_case default_case '}' 			
				{evt3(&$$,&$3,&$6,&$7);long_switch=max(long_switch,$$.node.val);}
;
compound_case:
	single_case 							{evt1(&$$,&$1);}//printf("comp -> %d\n",$1.node.len);}
|	single_case compound_case				{evt2(&$$,&$1,&$2);}//printf("comp -> %d %d\n",$1.node.len,$2.node.len);}
;
single_case:
	CASE integerLit ':' stmt_list			{evt2(&$$,&$2,&$4);}
;
default_case:
	DEFAULT ':' stmt_list					{evt1(&$$,&$3);}
;
assign_stmt:
	identifier EQ expr EOL 						{evt2(&$2,&$1,&$3);evt1(&$$,&$2);}
|	identifier '[' expr ']' EQ expr EOL			{evt3(&$5,&$1,&$3,&$6);evt1(&$$,&$5);}
|	identifier ARROW identifier EQ expr EOL		{evt3(&$4,&$1,&$3,&$5);evt1(&$$,&$4);}
|	identifier '.' identifier EQ expr EOL		{evt3(&$4,&$1,&$3,&$5);evt1(&$$,&$4);}
;
incr_stmt:
	identifier INC_OP EOL					{evt1(&$$,&$1);}
;
decr_stmt:
	identifier DEC_OP EOL					{evt1(&$$,&$1);}
;
expr:
	Pexpr '<' Pexpr							{evt2(&$2,&$1,&$3);evt1(&$$,&$2);}
|	Pexpr '>' Pexpr							{evt2(&$2,&$1,&$3);evt1(&$$,&$2);}
|	Pexpr LESS_OR_EQUAL Pexpr				{evt2(&$2,&$1,&$3);evt1(&$$,&$2);}
|	Pexpr GREATER_OR_EQUAL Pexpr			{evt2(&$2,&$1,&$3);evt1(&$$,&$2);}
|	Pexpr OR_OP Pexpr						{evt2(&$2,&$1,&$3);evt1(&$$,&$2);}
|	SIZE_OF '(' Pexpr ')'					{evt1(&$$,&$3);}
|	Pexpr EQUAL Pexpr						{evt2(&$2,&$1,&$3);evt1(&$$,&$2);}
|	Pexpr NOT_EQUAL Pexpr					{evt2(&$2,&$1,&$3);evt1(&$$,&$2);}
|	Pexpr THREE_WAY_OP Pexpr				{evt2(&$2,&$1,&$3);evt1(&$$,&$2);}
|	Pexpr AND_OP Pexpr						{evt2(&$2,&$1,&$3);evt1(&$$,&$2);}
|	Pexpr ARROW Pexpr						{evt2(&$2,&$1,&$3);evt1(&$$,&$2);}
|	Pexpr '+' Pexpr							{evt2(&$2,&$1,&$3);evt1(&$$,&$2);}
|	Pexpr '-' Pexpr							{evt2(&$2,&$1,&$3);evt1(&$$,&$2);}
|	Pexpr '*' Pexpr							{evt2(&$2,&$1,&$3);evt1(&$$,&$2);}
|	Pexpr '/' Pexpr							{evt2(&$2,&$1,&$3);evt1(&$$,&$2);}
|	Pexpr '%' Pexpr							{evt2(&$2,&$1,&$3);evt1(&$$,&$2);}
|	'!' Pexpr								{evt1(&$$,&$2);}
|	'-' Pexpr								{evt1(&$$,&$2);}
|	'+' Pexpr								{evt1(&$$,&$2);}
|	'*' Pexpr								{evt1(&$$,&$2);}
|	'&' Pexpr								{evt1(&$$,&$2);}
|	Pexpr									{evt1(&$$,&$1);}
|	identifier '(' args ')'					{evt2(&$$,&$1,&$3);}
|	identifier '[' expr ']'					{evt2(&$$,&$1,&$3);}
;
Pexpr:
	integerLit								{evt1(&$$,&$1);}
|	floatLit								{evt1(&$$,&$1);}
|	identifier								{evt1(&$$,&$1);}
|	'(' expr ')'							{evt1(&$$,&$2);}
;
integerLit:
	INT_NUMBER								{$$.node = (container){2,2};$$.sz=1;}
|	HEX 									{$$.node = (container){2,2};$$.sz=1;}
;
floatLit:
	INT_NUMBER '.' INT_NUMBER				{$$.node = (container){2,2};$$.sz=1;}
|	'.' INT_NUMBER							{$$.node = (container){2,2};$$.sz=1;}
;
identifier:
	ID 										
			{$$.node = (container){2,2};$$.sz=1;if(strcmp(temp,"main")==0){in_main+=1;}}
;
arg_list:
	expr 									{evt1(&$$,&$1);}
|	arg_list ',' expr						{evt2(&$$,&$1,&$3);}
;
args:
	arg_list								{evt1(&$$,&$1);}
|	%empty									{$$.node = (container){2,2};$$.sz=1;}
;
%%


void yyerror(char *s) {
	printf("syntax error\n");
	exit(1);
}

int main(){
	yyparse();
    printf("%d\n",long_all);
   	printf("%d\n",long_if);
   	printf("%d\n",long_while);
   	printf("%d\n",long_switch);
   	printf("%d\n",long_main);
    return 0;
}