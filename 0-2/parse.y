%{
#include "lex.yy.h"
#include "main.h"
%}

%union {
  char *word;
}

%token <word> WORD

%%
sentence: WORD WORD { printf("WORD(%s) WORD(%s)\n", $1, $2); }
        ;
%%
