%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	typedef struct details{
		int len;
		int val;
		char name[100];
		int value;
	}details;
	typedef struct Node{
		details node;
		int sz;
		struct Node* children[10];
	}Node;
	typedef struct variable
	{
		char name[100];
		int depth;
		struct variable* next;	
		int is_arr;	
	}var;
	var* arr_head[30];
	var* arr_tail[30];
	int func_count=0;
	int curr_func=0;
	void yyerror(char *);
	int yylex(void);
	char temp_id[100];
	char temp_int[100];
	char func_start[200];
	char func_end[200];
	int returned[30];
	extern char *yytext; 	
	int error=0;
	int expr_depth=-4;
	int label=0;
	int global_index=0;
	int param_count[30];
	int arg_count[30];
	int max(int i,int j){
		if(i<j)return j;
		return i;
	}
	void update(Node* root){
		if(root->sz==0)return;
		if(root->sz==1){
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
		root->children[0]=c1;
		root->children[1]=c2;
		root->children[2]=c3;
		root->sz=3;
		update(root);
	}
	void evt4(Node *root,Node *c1,Node *c2,Node *c3,Node* c4){
		root->children[0]=c1;
		root->children[1]=c2;
		root->children[2]=c3;
		root->children[3]=c4;
		root->sz=4;
		update(root);
	}
	Node* make(Node * root){
		root = (Node*)malloc(sizeof(Node));
		return root;
	}
	Node* ptr;
	void name(Node* root,char* arr){
		strcpy(root->node.name,arr);
	}
	#define YYSTYPE Node*
%}

%token IF ELSE RETURN DO WHILE FOR SWITCH BREAK CONTINUE EQ EOL EXTERN STRUCT CASE DEFAULT
%token INT LONG SHORT FLOAT DOUBLE CHAR VOID STRING SIZE_OF
%token LESS_OR_EQUAL GREATER_OR_EQUAL EQUAL NOT_EQUAL INC_OP DEC_OP 
%token AND_OP OR_OP THREE_WAY_OP PRINTF ARROW FORMAT_SPEC
%token ID INT_NUMBER HEX 

%start program


%%
program:										
	decl_list								{$$=make($$);name($$,"program");evt1($$,$1);ptr=$$;}							
;
decl_list:									
	decl  									{$$=make($$);name($$,"decl");evt1($$,$1);}	
|	decl_list decl							{$$=make($$);name($$,"decl_list");evt2($$,$1,$2);}	
;
decl:
	var_decl								{$$=make($$);evt1($$,$1);}	
|	func_decl								{$$=make($$);evt1($$,$1);}
|	struct_decl          					{$$=make($$);evt1($$,$1);}
;
struct_decl:
	STRUCT identifier '{' local_decs '}' EOL	{$$=make($$);evt2($$,$2,$4);}
;
var_decl:
	type_spec identifier EOL								{$$=make($$);name($$,"var_decl");evt2($$,$1,$2);}
|	type_spec identifier ',' var_decl						{$$=make($$);name($$,"var_decl");evt3($$,$1,$2,$4);}
|	type_spec identifier '[' integerLit ']' EOL 			{$$=make($$);name($$,"var_decl");evt3($$,$1,$2,$4);}
|	type_spec identifier '[' integerLit ']' ',' var_decl	{$$=make($$);name($$,"var_decl");evt4($$,$1,$2,$4,$7);}
;
type_spec:
	extern_spec VOID 						{$$=make($$);evt1($$,$1);}
|	extern_spec INT 						{$$=make($$);evt1($$,$1);name($$,"INT");}
|	extern_spec FLOAT  						{$$=make($$);evt1($$,$1);}
|	extern_spec VOID '*'    				{$$=make($$);evt1($$,$1);}
|	extern_spec INT '*' 					{$$=make($$);evt1($$,$1);}
|	extern_spec FLOAT '*' 					{$$=make($$);evt1($$,$1);}
|	STRUCT identifier 						{$$=make($$);evt1($$,$2);}
|	STRUCT identifier '*'   				{$$=make($$);evt1($$,$2);}
;
extern_spec:
	EXTERN 									{$$=make($$);$$->node = (details){2,2};$$->sz=1;}
|	%empty									{$$=make($$);$$->node = (details){2,2};$$->sz=1;}
;
func_decl:
	type_spec identifier '(' params ')' compound_stmt 		
		{$$=make($$);name($$,"funcdecl");evt4($$,$1,$2,$4,$6);}
;
params:
	param_list 								{$$=make($$);name($$,"params");evt1($$,$1);}
|	%empty 									{$$=make($$);$$->node = (details){2,2};name($$,"empty");$$->sz=1;}	
;
param_list:
	param 									{$$=make($$);name($$,"param_list");evt1($$,$1);}
|	param_list ',' param					{$$=make($$);name($$,"param_list");evt2($$,$1,$3);}
;
param:
	type_spec identifier					{$$=make($$);name($$,"param");evt2($$,$1,$2);}
|	type_spec identifier '[' ']'			{$$=make($$);name($$,"param");evt2($$,$1,$2);}
;
stmt_list:
	stmt 									{$$=make($$);evt1($$,$1);}
|	stmt_list stmt							{$$=make($$);evt2($$,$1,$2);}
;
stmt:
	assign_stmt								{$$=make($$);evt1($$,$1);}
|	compound_stmt							{$$=make($$);evt1($$,$1);}
|	if_stmt									{$$=make($$);evt1($$,$1);}
|	while_stmt								{$$=make($$);evt1($$,$1);}
|	switch_stmt								{$$=make($$);evt1($$,$1);}
|	return_stmt								{$$=make($$);evt1($$,$1);}
|	break_stmt								{$$=make($$);evt1($$,$1);}
|	continue_stmt							{$$=make($$);evt1($$,$1);}
|	dowhile_stmt							{$$=make($$);evt1($$,$1);}
|	print_stmt								{$$=make($$);evt1($$,$1);}
|	incr_stmt								{$$=make($$);evt1($$,$1);}
|	decr_stmt								{$$=make($$);evt1($$,$1);}
;
while_stmt:
	WHILE '(' expr ')' stmt 	
					{$$=make($$);name($$,"WHILE");evt2($$,$3,$5);}
;
dowhile_stmt:
	DO stmt WHILE '(' expr ')' EOL   		{$$=make($$);evt2($$,$2,$5);}
;
print_stmt:
	PRINTF '(' format_specifier ',' identifier ')' EOL		{$$=make($$);name($$,"PRINTF");evt2($$,$3,$5);}
;
format_specifier:
	FORMAT_SPEC 							{$$=make($$);$$->node = (details){2,2};$$->sz=1;}
;
compound_stmt:
	'{' local_decs stmt_list '}'			{$$=make($$);name($$,"compstmt");evt2($$,$2,$3);}
;
local_decs:
	local_decl local_decs					{$$=make($$);evt2($$,$1,$2);}
|	%empty									{$$=make($$);$$->node = (details){2,2};name($$,"empty");$$->sz=1;}
;
local_decl:	
	type_spec identifier EOL					{$$=make($$);name($$,"var_decl");evt2($$,$1,$2);}
|	type_spec identifier '[' expr ']' EOL		{$$=make($$);name($$,"var_decl");evt3($$,$1,$2,$4);}	
;
if_stmt:
	IF '(' expr ')' stmt 					{$$=make($$);name($$,"IF");evt2($$,$3,$5);}
|	IF '(' expr ')' stmt ELSE stmt 			{$$=make($$);name($$,"IF");evt3($$,$3,$5,$7);}
;
return_stmt:
	RETURN EOL								{$$=make($$);;$$->node = (details){2,2};name($$,"RETURN");$$->sz=0;}
|	RETURN expr EOL							{$$=make($$);name($$,"RETURN");evt1($$,$2);}
;
break_stmt:
	BREAK EOL								{$$=make($$);$$->node = (details){2,2};$$->sz=1;}
;
continue_stmt:
	CONTINUE EOL							{$$=make($$);$$->node = (details){2,2};$$->sz=1;}
;
switch_stmt:
	SWITCH '(' expr ')' '{' compound_case default_case '}' 			
				{$$=make($$);evt3($$,$3,$6,$7);}
;
compound_case:
	single_case 							{$$=make($$);evt1($$,$1);}
|	single_case compound_case				{$$=make($$);evt2($$,$1,$2);}
;
single_case:
	CASE integerLit ':' stmt_list			{$$=make($$);evt2($$,$2,$4);}
;
default_case:
	DEFAULT ':' stmt_list					{$$=make($$);evt1($$,$3);}
;
assign_stmt:
	identifier EQ expr EOL 						{$$=make($$);name($$,"assign");$2=make($2);evt2($2,$1,$3);evt1($$,$2);}
|	identifier '[' expr ']' EQ expr EOL			{$$=make($$);name($$,"assign");$5=make($5);evt3($5,$1,$3,$6);evt1($$,$5);}
|	identifier ARROW identifier EQ expr EOL		{$$=make($$);name($$,"assign");$4=make($4);evt3($4,$1,$3,$5);evt1($$,$4);}
|	identifier '.' identifier EQ expr EOL		{$$=make($$);name($$,"assign");$4=make($4);evt3($4,$1,$3,$5);evt1($$,$4);}
;
incr_stmt:
	identifier INC_OP EOL					{$$=make($$);name($$,"inc");evt1($$,$1);}
;
decr_stmt:
	identifier DEC_OP EOL					{$$=make($$);name($$,"dec");evt1($$,$1);}
;
expr:
	Pexpr '<' Pexpr							{$$=make($$);name($$,"expr");$2=make($2);name($2,"<");evt2($2,$1,$3);evt1($$,$2);}
|	Pexpr '>' Pexpr							{$$=make($$);name($$,"expr");$2=make($2);name($2,">");evt2($2,$1,$3);evt1($$,$2);}
|	Pexpr LESS_OR_EQUAL Pexpr				{$$=make($$);name($$,"expr");$2=make($2);name($2,"<=");evt2($2,$1,$3);evt1($$,$2);}
|	Pexpr GREATER_OR_EQUAL Pexpr			{$$=make($$);name($$,"expr");$2=make($2);name($2,">=");evt2($2,$1,$3);evt1($$,$2);}
|	Pexpr OR_OP Pexpr						{$$=make($$);name($$,"expr");$2=make($2);name($2,"||");evt2($2,$1,$3);evt1($$,$2);}
|	SIZE_OF '(' Pexpr ')'					{$$=make($$);name($$,"sizeof");evt1($$,$3);}
|	Pexpr EQUAL Pexpr						{$$=make($$);name($$,"expr");$2=make($2);name($2,"==");evt2($2,$1,$3);evt1($$,$2);}
|	Pexpr NOT_EQUAL Pexpr					{$$=make($$);name($$,"expr");$2=make($2);name($2,"!=");evt2($2,$1,$3);evt1($$,$2);}
|	Pexpr THREE_WAY_OP Pexpr				{$$=make($$);name($$,"expr");$2=make($2);name($2,"<=>");evt2($2,$1,$3);evt1($$,$2);}
|	Pexpr AND_OP Pexpr						{$$=make($$);name($$,"expr");$2=make($2);name($2,"&&");evt2($2,$1,$3);evt1($$,$2);}
|	Pexpr ARROW Pexpr						{$$=make($$);name($$,"expr");$2=make($2);evt2($2,$1,$3);evt1($$,$2);}
|	Pexpr '+' Pexpr							
	{$$=make($$);name($$,"expr");$2=make($2);name($2,"+");evt2($2,$1,$3);evt1($$,$2);}
|	Pexpr '-' Pexpr							
	{$$=make($$);name($$,"expr");$2=make($2);name($2,"-");evt2($2,$1,$3);evt1($$,$2);}
|	Pexpr '*' Pexpr							
	{$$=make($$);name($$,"expr");$2=make($2);name($2,"*");evt2($2,$1,$3);evt1($$,$2);}
|	Pexpr '/' Pexpr							
	{$$=make($$);name($$,"expr");$2=make($2);name($2,"/");evt2($2,$1,$3);evt1($$,$2);}
|	Pexpr '%' Pexpr							
	{$$=make($$);name($$,"expr");$2=make($2);name($2,"%");evt2($2,$1,$3);evt1($$,$2);}
|	'!' Pexpr								{$$=make($$);$1=make($1);name($1,"!");name($$,"expr");evt2($$,$1,$2);}
|	'-' Pexpr								{$$=make($$);$1=make($1);name($1,"-");name($$,"expr");evt2($$,$1,$2);}
|	'+' Pexpr								{$$=make($$);$1=make($1);name($1,"+");name($$,"expr");evt2($$,$1,$2);}
|	'*' Pexpr								{$$=make($$);$1=make($1);name($1,"*");name($$,"expr");evt2($$,$1,$2);}
|	'&' Pexpr								{$$=make($$);$1=make($1);name($1,"&");name($$,"expr");evt2($$,$1,$2);}
|	Pexpr									{$$=make($$);name($$,"expr");evt1($$,$1);$$->node.value=$1->node.value;}
|	identifier '(' args ')'					{$$=make($$);name($$,"func_call");evt2($$,$1,$3);}
|	identifier '[' expr ']'					{$$=make($$);name($$,"arrexpr");evt2($$,$1,$3);$$->node.value=$3->node.value;}
;
Pexpr:
	integerLit								{$$=make($$);evt1($$,$1);name($$,"pexpr");$$->node.value=$1->node.value;}
|	floatLit								{$$=make($$);evt1($$,$1);name($$,"pexpr");}
|	identifier								{$$=make($$);evt1($$,$1);name($$,"pexpr");}
|	'(' expr ')'							{$$=make($$);evt1($$,$2);name($$,"pexpr");$$->node.value=$2->node.value;}
;
integerLit:
	INT_NUMBER								
		{$$=make($$);$$->node = (details){2,2};name($$,"int");$$->sz=1;$$->node.value=atoi(temp_int);}
|	HEX 									{$$=make($$);$$->node = (details){2,2};$$->sz=1;}
;
floatLit:
	INT_NUMBER '.' INT_NUMBER				{$$=make($$);name($$,"float");$$->node = (details){2,2};$$->sz=1;}
|	'.' INT_NUMBER							{$$=make($$);$$->node = (details){2,2};$$->sz=1;}
;
identifier:
	ID 										
	{$$=make($$);$$->node = (details){2,2};name($$,temp_id);$$->sz=1;}
;
arg_list:
	expr 									{$$=make($$);name($$,"arglist");evt1($$,$1);}
|	arg_list ',' expr						{$$=make($$);name($$,"arglist");evt2($$,$1,$3);}
;
args:
	arg_list								{$$=make($$);name($$,"args");evt1($$,$1);}
|	%empty									{$$=make($$);$$->node = (details){2,2};name($$,"empty");$$->sz=1;}
;
%%


void yyerror(char *s) {
	printf("syntax error\n");
	exit(1);
}
void dfs(Node* ptr){
	if(!ptr)return;
	if(strcmp(ptr->node.name,"IF")==0){
		int x = label;
		label+=2;
		printf("//\tIF START\n");
		dfs(ptr->children[0]);	
		printf("\tcmpl\t$0, %%r8d\n");
		printf("\tjz  \t_ifnot%d\n",x+1);
		dfs(ptr->children[1]);
		if(ptr->sz==3){
			printf("\tjmp \t_ifnot%d\n", x+2);
		}
		printf("_ifnot%d:\n", x+1);	
		if(ptr->sz==3){
			dfs(ptr->children[2]);
			printf("_ifnot%d:\n",x+2 );
		}
		printf("//\tIF END\n");
	}
	//15 17 18 19
	else if(strcmp(ptr->node.name,"WHILE")==0){
		int x = label;
		label+=2;
		printf("//\tWHILE START\n");
		printf("_whileout%d:\n", x+1);
		dfs(ptr->children[0]);
		printf("\tcmpl\t$0, %%r8d\n");
		printf("\tjz  \t_whileout%d\n",x+2);
		dfs(ptr->children[1]);
		printf("\tjmp \t_whileout%d\n",x+1);
		printf("_whileout%d:\n",x+2);
		printf("//\tWHILE END\n");
		x+=2;
	}
	else if(strcmp(ptr->node.name,"sizeof")==0){
		var* temp_var=arr_head[curr_func];
		while(temp_var){
			if(strcmp(temp_var->name,ptr->children[0]->children[0]->node.name)==0){
				printf("\tmovl\t$%d, %%r8d\n", temp_var->depth);
				break;
			}
			temp_var=temp_var->next;  
		}

	}
	else if(strcmp(ptr->node.name,"inc")==0){
		var* temp_var=arr_head[curr_func];
		int d=0;
		while(temp_var){
			d+=temp_var->depth;
			if(strcmp(temp_var->name,ptr->children[0]->node.name)==0){
				printf("\tadd \t$1, -%d(%%rbp)\n",d);
				break;
			}
			temp_var=temp_var->next;  
		}
	}
	else if(strcmp(ptr->node.name,"dec")==0){
		var* temp_var=arr_head[curr_func];
		int d=0;
		while(temp_var){
			d+=temp_var->depth;
			if(strcmp(temp_var->name,ptr->children[0]->node.name)==0){
				printf("\tsub \t$1, -%d(%%rbp)\n",d);
				break;
			}
			temp_var=temp_var->next;  
		}
	}
	else if(strcmp(ptr->node.name, "funcdecl")==0){
		arr_head[func_count]=(var*)malloc(sizeof(var));
		arr_head[func_count]->depth=-1;
		arr_head[func_count]->next=NULL;
		arr_tail[func_count]=arr_head[func_count];
		curr_func=func_count; 	
		returned[curr_func]=0;
		printf("\t.globl\t%s\n", ptr->children[1]->node.name);
		printf("\t.type\t%s, @function\n", ptr->children[1]->node.name);
		printf("%s:\n", ptr->children[1]->node.name);
		printf(".LFB%d:\n", global_index);
		printf("%s\n", func_start);
		dfs(ptr->children[2]);
		dfs(ptr->children[3]);
		if(!returned[curr_func]){
			printf("\tmovl\t$0, %%eax\n");
			printf("\tmovq\t%%rbp, %%rsp\n\tpopq\t%%rbp\n");
		}
		printf("_func%d:\n", curr_func);
		printf("%s\n", func_end);
		printf(".LFE%d:\n",global_index);
		printf("\t.size\t%s, .-%s\n", ptr->children[1]->node.name,ptr->children[1]->node.name);
		global_index++;
		func_count++;
	}
	else if(strcmp(ptr->node.name,"RETURN")==0){
		printf("//in return\n");
		returned[curr_func]=1;
		if(ptr->sz==0){
			printf("\tmovl\t$0, %%eax\n");
			printf("\tmovq\t%%rbp, %%rsp\n\tpopq\t%%rbp\n");
			printf("\tjmp\t_func%d\n", curr_func);
		}
		else{
			dfs(ptr->children[0]);
			printf("\tmovl\t%%r8d, %%eax\n");
			printf("\tmovq\t%%rbp, %%rsp\n\tpopq\t%%rbp\n");
			printf("\tjmp\t_func%d\n", curr_func);
		}
	}
	else if(strcmp(ptr->node.name, "empty")==0){
		return;
	}
	else if(strcmp(ptr->node.name, "params")==0){
		dfs(ptr->children[0]);
		int i=1;
		while(i<=param_count[curr_func]){
			printf("\tmovl\t%%r%dd, %%eax\n", 9+i);
			printf("\tmovl\t%%eax, %d(%%rbp)\n", -4*i);
			i++;
		}
		for(int i=0;i<param_count[curr_func];i++){
			printf("\tsubq\t$4, %%rsp\n");
		}
	}
	else if(strcmp(ptr->node.name, "param_list")==0){
		if(ptr->sz==1){
			param_count[curr_func]++;
			dfs(ptr->children[0]);
		}
		else{
			param_count[curr_func]++;
			dfs(ptr->children[0]);
			dfs(ptr->children[1]);
		}
	}
	else if(strcmp(ptr->node.name,"param")==0){
		if(arr_head[curr_func]->depth==-1){
			strcpy(arr_head[curr_func]->name,ptr->children[1]->node.name);
			arr_head[curr_func]->depth=4;
		}
		else{
			var* nw_var=(var*)malloc(sizeof(var));
			strcpy(nw_var->name,ptr->children[1]->node.name);
			nw_var->depth=4;
			if(!arr_head[curr_func]->next)arr_head[curr_func]->next=nw_var;
			arr_tail[func_count]->next = nw_var;
			arr_tail[func_count]=arr_tail[func_count]->next;
		}
	}
	else if(strcmp(ptr->node.name,"args")==0){
		arg_count[curr_func]=1;
		dfs(ptr->children[0]);
	}
	else if(strcmp(ptr->node.name,"arglist")==0){
		if(ptr->sz==1){
			dfs(ptr->children[0]);
			printf("\tmovl\t%%r8d, %%eax\n");
			printf("\tmovl\t%%eax, %%r%dd\n", 9+arg_count[curr_func]);
			arg_count[curr_func]++;
		}
		else{
			dfs(ptr->children[0]);
			dfs(ptr->children[1]);
			printf("\tmovl\t%%r8d, %%eax\n");
			printf("\tmovl\t%%eax, %%r%dd\n", 9+arg_count[curr_func]);
			arg_count[curr_func]++;
		}
	}
	else if(strcmp(ptr->node.name,"func_call")==0){
		dfs(ptr->children[1]);
		printf("\tsubq\t$1024, %%rsp\n");
		printf("\tcall\t%s\n", ptr->children[0]->node.name);
		printf("\tadd \t$1024, %%rsp\n");
		printf("\tmovl\t%%eax, %%r8d\n");
	}
	else if(strcmp(ptr->node.name,"pexpr")==0){
		if(strcmp(ptr->children[0]->node.name,"int")==0){
			printf("\tmovl\t$%d, %d(%%rsp)\n", ptr->children[0]->node.value,expr_depth);
		}
		else if(strcmp(ptr->children[0]->node.name,"expr")==0 || strcmp(ptr->children[0]->node.name,"func_call")==0 || strcmp(ptr->children[0]->node.name,"arrexpr")==0 ){
			dfs(ptr->children[0]);
			printf("\tmovl\t%%r8d, %d(%%rsp)\n", expr_depth);
		}
		else{
			var* temp_var=arr_head[curr_func];
			int d=0;
			while(temp_var){
				d+=temp_var->depth;
				if(strcmp(temp_var->name,ptr->children[0]->node.name)==0){
					printf("\tmovl\t-%d(%%rbp), %%eax\n",d);
					printf("\tmovl\t%%eax, %d(%%rsp)\n",expr_depth);
					break;
				}
				temp_var=temp_var->next;  
			}
		}
	}
	else if(strcmp(ptr->node.name,"arrexpr")==0){
		var* temp_var=arr_head[curr_func];
		int d=0;
		int prev=0;
		while(temp_var){
			prev=d;
			d+=temp_var->depth;
			if(strcmp(temp_var->name,ptr->children[0]->node.name)==0){
				dfs(ptr->children[1]);
				printf("\tmovl\t%%r8d, %%eax\n");
				printf("\tmovl\t-%d(%%rbp, %%rax, 4), %%r8d\n",d);
				break;
			}
			temp_var=temp_var->next;  
		}
	}
	else if(strcmp(ptr->node.name,"expr")==0){
		int x = label;
		label+=2;
		printf("//\tEXPR EVALUATION\n");
		char val[100];strcpy(val,ptr->children[0]->node.name);
		if(strcmp(val,"pexpr")==0){
			if(strcmp(ptr->children[0]->children[0]->node.name,"int")==0){
				printf("\tmovl\t$%d, %d(%%rsp)\n", ptr->children[0]->children[0]->node.value,expr_depth);
			}
			else if(strcmp(ptr->children[0]->children[0]->node.name,"expr")==0){
				expr_depth-=4;
				dfs(ptr->children[0]->children[0]);
				expr_depth+=4;
				printf("\tmovl\t%%r8d, %d(%%rsp)\n", expr_depth);
			}
			else{
				var* temp_var=arr_head[curr_func];
				int d=0;
				while(temp_var){
					d+=temp_var->depth;
					if(strcmp(temp_var->name,ptr->children[0]->children[0]->node.name)==0){
						printf("\tmovl\t-%d(%%rbp), %%eax\n",d);
						printf("\tmovl\t%%eax, %d(%%rsp)\n",expr_depth);
						break;
					}
					temp_var=temp_var->next;  
				}
			}
		}
		else if(strcmp(val,"+")==0 || strcmp(val,"-")==0){
			if(ptr->children[0]->sz==2){
				printf("//\t come here\n");
				dfs(ptr->children[0]->children[0]);
				expr_depth-=4;
				dfs(ptr->children[0]->children[1]);
				expr_depth+=4;
				printf("\tmovl\t%d(%%rsp), %%eax\n",expr_depth-4);
				printf("\tmovl\t%d(%%rsp), %%edx\n",expr_depth);
				if(strcmp(val,"+")==0){
					printf("\tadd \t%%eax, %%edx\n");
				}
				else{
					printf("\tsub \t%%eax, %%edx\n");
				}
				printf("\tmovl\t%%edx, %d(%%rsp)\n",expr_depth);	
			}
			else{
				dfs(ptr->children[1]);	
				if(strcmp(val,"-")==0){
					printf("\tmovl\t%d(%%rsp), %%eax\n",expr_depth);
					printf("\tmovl\t$-1, %%edx\n");
					printf("\timul\t%%eax, %%edx\n");
					printf("\tmovl\t%%edx, %d(%%rsp)\n", expr_depth);
				}
			}
		}
		else if(strcmp(val,"!")==0){
			dfs(ptr->children[1]);
			printf("\tmovl\t%d(%%rsp), %%eax\n",expr_depth);
			printf("\tnot \t%%eax\n");
			printf("\tmovl\t%%eax, %d(%%rsp)\n",expr_depth );

		}
		else if(strcmp(val,"*")==0){
			if(ptr->children[0]->sz==2){
				dfs(ptr->children[0]->children[0]);
				expr_depth-=4;
				dfs(ptr->children[0]->children[1]);
				expr_depth+=4;
				printf("\tmovl\t%d(%%rsp), %%eax\n",expr_depth-4);
				printf("\tmovl\t%d(%%rsp), %%edx\n",expr_depth);
				printf("\timul\t%%eax, %%edx\n");
				printf("\tmovl\t%%edx, %d(%%rsp)\n", expr_depth);	
			}
			else{
				var* temp_var=arr_head[curr_func];
				int d=0;
				int prev=0;
				while(temp_var){
					prev=d;
					d+=temp_var->depth;
					if(strcmp(temp_var->name,ptr->children[1]->children[0]->node.name)==0){
						printf("\tmovl\t-%d(%%rbp), %%eax\n",prev+4+4*ptr->children[1]->node.value);
						printf("\tmovl\t%%eax, %d(%%rsp)\n",expr_depth);
						break;
					}
					temp_var=temp_var->next;  
				}
			}	
		}
		else if(strcmp(val,"/")==0){
			dfs(ptr->children[0]->children[0]);
			expr_depth-=4;
			dfs(ptr->children[0]->children[1]);
			expr_depth+=4;
			printf("\tmovl\t%d(%%rsp), %%eax\n",expr_depth);
			printf("\tcltd\n");
			printf("\tmovl\t%d(%%rsp), %%r9d\n",expr_depth-4);
			printf("\tidivl\t%%r9d\n");
			printf("\tmovl\t%%eax, %d(%%rsp)\n", expr_depth);	
		}
		else if(strcmp(val,"%")==0){
			dfs(ptr->children[0]->children[0]);
			expr_depth-=4;
			dfs(ptr->children[0]->children[1]);
			expr_depth+=4;
			printf("\tmovl\t%d(%%rsp), %%eax\n",expr_depth);
			printf("\tcltd\n");
			printf("\tmovl\t%d(%%rsp), %%r9d\n",expr_depth-4);
			printf("\tidivl\t%%r9d\n");
			printf("\tmovl\t%%edx, %d(%%rsp)\n", expr_depth);	
		}
		else if(strcmp(val,"&&")==0 || strcmp(val,"||")==0){
			dfs(ptr->children[0]->children[0]);
			printf("\tcmpl\t$0, %d(%%rsp)\n",expr_depth);
			printf("\tjz  \t_bi_end%d\n",x+1);
			expr_depth-=4;
			dfs(ptr->children[0]->children[1]);
			expr_depth+=4;
			printf("\tcmpl\t$0, %d(%%rsp)\n",expr_depth-4);
			if(strcmp(val,"&&")==0){
				printf("\tjz  \t_bi_end%d\n",x+1);
				printf("\tmovl\t$1, %d(%%rsp)\n", expr_depth);
				printf("\tjmp \t_bi%d\n",x+1);
				printf("_bi_end%d:\n", x+1);
				printf("\tmovl\t$0, %d(%%rsp)\n", expr_depth);
			}
			else{
				printf("\tjnz  \t_bi_end%d\n",x+1);
				printf("\tmovl\t$0, %d(%%rsp)\n", expr_depth);
				printf("\tjmp \t_bi%d\n",x+1);
				printf("_bi_end%d:\n", x+1);
				printf("\tmovl\t$1, %d(%%rsp)\n", expr_depth);	
			}
			printf("_bi%d:\n", x+1);
		}
		else if(strcmp(val,"<=>")==0){
			dfs(ptr->children[0]->children[0]);
			expr_depth-=4;
			dfs(ptr->children[0]->children[1]);
			expr_depth+=4;
			printf("\tmovl\t%d(%%rsp), %%eax\n", expr_depth);
			printf("\tmovl\t%d(%%rsp), %%edx\n", expr_depth-4);
			printf("\tcmpl %%eax, %%edx\n");
			printf("\tjg  \t_threeway_g%d\n",x+1);
			printf("\tjl  \t_threeway_l%d\n",x+1);
			printf("\tmovl\t$0, %d(%%rsp)\n", expr_depth);
			printf("\tjmp \t_threeway_end%d\n",x+1);
			printf("_threeway_g%d:\n",x+1);
			printf("\tmovl\t$-1, %d(%%rsp)\n", expr_depth);
			printf("\tjmp \t_threeway_end%d\n",x+1);
			printf("_threeway_l%d:\n",x+1);
			printf("\tmovl\t$1, %d(%%rsp)\n", expr_depth);
			printf("_threeway_end%d:\n",x+1);
		}
		else{
			dfs(ptr->children[0]->children[0]);
			expr_depth-=4;
			dfs(ptr->children[0]->children[1]);
			expr_depth+=4;
			printf("\tmovl\t%d(%%rsp), %%eax\n", expr_depth);
			printf("\tmovl\t%d(%%rsp), %%edx\n", expr_depth-4);
			printf("\tcmpl\t%%eax, %%edx\n");
			if(strcmp(val,"==")==0){
				printf("\tjnz  \t_neq%d\n",x+1);
			}
			else if(strcmp(val,"!=")==0){
				printf("\tjz  \t_neq%d\n",x+1);
			}
			else if(strcmp(val,"<")==0){
				printf("\tjle \t_neq%d\n",x+1);
			}
			else if(strcmp(val,"<=")==0){
				printf("\tjl  \t_neq%d\n",x+1);
			}
			else if(strcmp(val,">")==0){
				printf("\tjge \t_neq%d\n",x+1);
			}
			else if(strcmp(val,">=")==0){
				printf("\tjg  \t_neq%d\n",x+1);
			}
			printf("\tmovl\t$1, %d(%%rsp)\n", expr_depth);
			printf("\tjmp \t_eq%d\n",x+1 );
			printf("_neq%d:\n",x+1);
			printf("\tmovl\t$0, %d(%%rsp)\n", expr_depth);
			printf("_eq%d:\n",x+1);
		}
		printf("\tmovl\t%d(%%rsp), %%r8d\n",expr_depth);
		printf("//\tEXPR DONE\n");
	}
	else if(strcmp(ptr->node.name,"assign")==0){
		if(ptr->children[0]->sz==2){
			printf("//\tVAR ASSIGN\n");
			var* temp_var=arr_head[curr_func];
			int d=0;
			while(temp_var){
				d+=temp_var->depth;
				if(strcmp(temp_var->name,ptr->children[0]->children[0]->node.name)==0){
					dfs(ptr->children[0]->children[1]);
					printf("\tmovl\t%%r8d, -%d(%%rbp)\n",d);
					break;
				}
				temp_var=temp_var->next;
			}
			printf("//\tASSGN DONE\n");
		}
		/*
		|	identifier '[' expr ']' EQ expr EOL	{$$=make($$);name($$,"assign");$5=make($5);evt3($5,$1,$3,$6);evt1($$,$5);}
		*/
		else{
			printf("//\tARR ASSIGN\n");
			var* temp_var=arr_head[curr_func];
			int d=0;
			int prev=0;
			while(temp_var){
				prev=d;
				d+=temp_var->depth;
				if(strcmp(temp_var->name,ptr->children[0]->children[0]->node.name)==0){
					dfs(ptr->children[0]->children[1]);
					printf("\tmovl\t%%r8d, %%r11d\n");
					dfs(ptr->children[0]->children[2]);
					printf("\tmovl\t%%r11d, %%eax\n");
					printf("\tmovl\t%%r8d, %%r10d\n");
					printf("\tmovl\t%%r10d, -%d(%%rbp, %%rax, 4)\n", d);
					break;
				}
				temp_var=temp_var->next;
			}
			printf("//\tASSGN DONE\n");
		}
	}
	else if(strcmp(ptr->node.name,"var_decl")==0){
		printf("//\tVAR DEC\n");
		if(ptr->sz==2){
			if(arr_head[curr_func]->depth==-1){
				strcpy(arr_head[curr_func]->name,ptr->children[1]->node.name);
				arr_head[curr_func]->depth=4;
			}
			else{
				var* nw_var=(var*)malloc(sizeof(var));
				strcpy(nw_var->name,ptr->children[1]->node.name);
				nw_var->depth=4;
				if(!arr_head[curr_func]->next)arr_head[curr_func]->next=nw_var;
				arr_tail[func_count]->next = nw_var;
				arr_tail[func_count]=arr_tail[func_count]->next;
			}
			printf("\tsubq\t$4, %%rsp\n");
		}
		else if(ptr->sz==3){
			int d;
			if(arr_head[curr_func]->depth==-1){
				strcpy(arr_head[curr_func]->name,ptr->children[1]->node.name);
				arr_head[curr_func]->depth=4*ptr->children[2]->node.value;
				d=arr_head[curr_func]->depth;
				arr_tail[func_count]=arr_head[curr_func];
			}
			else{
				var* nw_var=(var*)malloc(sizeof(var));
				nw_var->is_arr=1;
				strcpy(nw_var->name,ptr->children[1]->node.name);
				nw_var->depth=4 * ptr->children[2]->node.value;
				d=nw_var->depth;
				if(!arr_head[curr_func]->next)arr_head[curr_func]->next=nw_var;
				arr_tail[func_count]->next = nw_var;
				arr_tail[func_count]=arr_tail[func_count]->next;
			}
			printf("\tsubq\t$%d, %%rsp\n",d);
		}
	}
	else if(strcmp(ptr->node.name,"PRINTF")==0){
		printf("\n//\tCALL TO PRINTF\n");
		var* temp_var=arr_head[curr_func];
		int d=0;
		int prev=0;
		while(temp_var){
			prev=d;
			d+=temp_var->depth;
			if(strcmp(temp_var->name,ptr->children[1]->node.name)==0){
				if(temp_var->is_arr==1){
					printf("\tmovl\t-%d(%%rbp), %%eax\n",prev+4);
					break;
				}
				else{
					printf("\tmovl\t-%d(%%rbp), %%eax\n",d);
					break;
				}
			}
			temp_var=temp_var->next;
		}
		printf("\tmovl\t%%eax, %%esi\n\tleaq\t.LC0(%%rip), %%rdi\n\tmovl\t$0, %%eax\n\tcall\tprintf@PLT\n");
		printf("//\tPRINTF END\n");
	}
	else{
		for(int i=0;i<ptr->sz;i++){
			dfs(ptr->children[i]);
		}
	}

}
int main(){
	char start_string[300]="\t.text\n\t.section	.rodata\n.LC0:\n\t.string\t\"%d\\n\"\n\t.text\n";
	
	strcpy(func_start,"\t.cfi_startproc\n\tpushq\t%rbp\n\
	.cfi_def_cfa_offset 16\n\t.cfi_offset 6, -16\n\tmovq\
	%rsp, %rbp\n\t.cfi_def_cfa_register 6");

	strcpy(func_end,"\t.cfi_def_cfa 7, 8\n\tret\n\t.cfi_endproc\n");

	char end_string[200]="\t.ident\t\"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0\"\n\t.section\t.note.GNU-stack,\"\",@progbits";

	printf("%s\n\n\n", start_string);
	yyparse();
   	dfs(ptr);
   	printf("\n\n%s\n", end_string);
    return 0;
}