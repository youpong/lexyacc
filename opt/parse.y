%{
#include "lex.yy.h"
#include "main.h"  
%}  
%token IDENT

%%
func_def:   IDENT '(' params_opt ')'
            ;
params_opt: /* epsilon */ { printf("params omitted\n"); }
            | params      { printf("params specified\n"); }
	    ;
params:     param ',' params
            | param
            ;
param:      IDENT { printf("param: (%s)\n", yytext); }
            ;
%%
