%{
#include <stdio.h>
%}
%option nounput noinput
%%
.|\n printf("%s", yytext);
%%
