%{
#include "y.tab.h"
%}
%%
[ \t]				;
return     			{return retu;}
if				{return IF;}
[+-]?[0-9][0-9]*    {yylval.num=atoi(yytext);return number;}
[a-zA-Z] 			{yylval.id=yytext[0];return identifier;}
[\+\-\*\/\[\]\=\n;]  {return yytext[0];}
">"					{return G;}
"<"					{return L;}
">="				{return GT;}
"<="				{return LT;}
"=="				{return EE;}
.					{printf("unknown symbol %c and line %d\n",*yytext,yylineno);}
%%
int yywrap(){
	return 0;
}
void yyerror(int error){}
