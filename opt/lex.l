%{
#include "y.tab.h"
%}
%option nounput noinput

delim  [ \t\n]
digit  [0-9]
letter [a-zA-Z]

ws     {delim}+
number {digit}+
id     {letter}({letter}|{digit})*

%%
{ws}   { ; /* igreno white space */ }
{id}   { return IDENT; }
.      { return yytext[0]; }
%%
