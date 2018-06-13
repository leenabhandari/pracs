%{
  #include "stdio.h"
  void yyerror(char *str);
  
  FILE *yyin;
%}

%token NOUN PRONOUN NEWLINE CONJUNCTION ADJECTIVE ADVERB VERB PREPOSITION ARTICLE

%%

sentence:sentence simple_sentence NEWLINE {printf("\nSimple sentence");}
|sentence NEWLINE
|sentence compound_sentence NEWLINE {printf("\nCompound sentence.");}
|
;

simple_sentence: subject VERB object
	;

subject:NOUN
	|PRONOUN
	|ADJECTIVE subject
	|ARTICLE subject
	|
	;


object:NOUN
	|ADJECTIVE object
	|ADVERB object
	|PREPOSITION NOUN
	|ARTICLE object
	|
	;

compound_sentence:simple_sentence CONJUNCTION simple_sentence
	|simple_sentence CONJUNCTION subject
	;

%%


int main()
{
yyin=fopen("eng.txt","r");
yyparse();
return 0;
}

void yyerror(char *str)
{
printf("Error");
}
