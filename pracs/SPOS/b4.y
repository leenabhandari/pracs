%{
#include<stdio.h>
%}

%token NUM 
%left'+''-'
%right'*''/'
%%
start:exp {printf("%d",$$);}
exp:exp'+'exp {$$=$1+$3;}
|exp'-'exp {$$=$1-$3;}
|exp'*'exp {$$=$1*$3;}
|exp'/'exp {if($3==0)yyerror("error"); else{ $$=$1/$3; }}
|'('exp')' {$$=$2;}
|NUM {$$=$1;}
;

%%

int main()
{

printf("Enter expression: ");
if(yyparse()==0)
	printf("\n correct");
else printf("\n Incorrect");
return 0;
}

yywrap(){};

void yyerror()
{
printf("error");
}

