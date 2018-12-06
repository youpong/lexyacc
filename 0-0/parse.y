%{
#include "lex.yy.h"
#include "main.h"
%}

%token WORD

%%
sentence: WORD
        | WORD sentence
        ;
%%
