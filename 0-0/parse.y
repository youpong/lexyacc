%{
#include "lex.yy.h"
#include "main.h"
%}

%token WORD

%%
sentence: WORD          { printf("WORD\n"); }
        | WORD sentence { printf("WORD "); }
        ;
%%
