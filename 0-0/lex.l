%{
#include "main.h"
#include <string.h>
%}
%option nounput noinput
%%
[ \t]     ; /* ignore */
\.\n      return 0;
[a-zA-Z]+ { word = strdup(yytext); return SYMB; }
.|\n      ; /* ignore */
%%
