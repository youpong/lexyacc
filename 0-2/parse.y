%{
#include "lex.yy.h"
#include "main.h"
%}

%union {
  char *word;
}

%token <word> WORD

%%
sentence: sentence WORD { printf("WORD(%d:%s) ", cnt++, $2); }
        | WORD          { printf("WORD(%d:%s) ", cnt++, $1); }
        ;
%%
