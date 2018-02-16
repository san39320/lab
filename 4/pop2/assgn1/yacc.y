%{	
	#include<string.h>
	#include<stdio.h>
	int symbols[52];
	int getIndex(char token)
	{
		int idx = -1;
		if(islower(token)) {
			idx = token - 'a' + 26;
		} else if(isupper(token)) {
			idx = token - 'A';
		}
		return idx;
	}
	int getthesymbolvalue(char symbol){
		int index = getIndex(symbol);
		return symbols[index];
	}
	void setsymbolvalue(char symbol,int value){
		int index = getIndex(symbol);
		symbols[index]=value;
	}
%}


%union { int num; char id; }
%start line
%token <num> number
%token <id> identifier
%token retu
%token GT
%token LT
%token EE
%token L
%token G
%token IF
%type <num> exp
%type <num> term

%%
line:
	exp '\n' { printf("%d\n",$1); exit(0);};
exp:
	'[' '+' exp exp ']' {$$=$3+$4;}|
	'[' '-' exp exp ']' {$$=$3-$4;}|
	'[' '*' exp exp ']' {$$=$3*$4;}|
	'[' '/' exp exp ']'{$$=$3/$4;}|
	'[' L exp exp ']' {$$=($3<$4)?1:0;}|
	'[' G exp exp ']' {$$=($3>$4)?1:0;}|
	'[' LT exp exp ']' {$$=($3<=$4)?1:0;}|
	'[' GT exp exp ']'{$$=($3<=$4)?1:0;}|
	'[' EE exp exp ']'{$$=($3==$4)?1:0;}|
	 term			{$$=$1;}|
	'[' IF exp '[' '=' identifier exp ']'  exp ']'  {if($3==1){setsymbolvalue($6,$7);};$$=$9;}|
	'[' IF exp '[' retu  exp ']'  exp ']'  {if($3==1){int a=$6;printf("%d\n",a);};$$=$8;}|

	'[' '=' identifier exp ']' {setsymbolvalue($3,$4);$$=$4;}|
	'[' ';' exp exp ']'  {$$=$4;} |
	'[' retu exp ']' {$$=$3;} ;
term:
	number {$$=$1;} |
	identifier {$$=getthesymbolvalue($1);};
%%
int main(){
	memset(symbols,0,26*sizeof(int));
	return yyparse();
}