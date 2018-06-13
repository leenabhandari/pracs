%{
#include "y.tab.h"

%}

%%
he|she {return PRONOUN;}
is|was|walking|dancing {return VERB;}
your|her|his {return ADJECTIVE;}
quietly|silently|gracefully {return ADVERB;}
a|an|the {return ARTICLE;}
[\n] {return NEWLINE;}
and|because|or {return CONJUNCTION;}
[a-zA-Z][a-zA-Z0-9]* {return NOUN;}
[ ] {}
. {yyerror("error");}
%%

int yywrap()
{
 return 1;
}
