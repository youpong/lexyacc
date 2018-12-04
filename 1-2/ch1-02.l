%{
/*
 * this sample demonstrates (very) simple recognition:
 * a verb/not a verb
 */
#include <stdlib.h>
#include <stdio.h>
%}

%option nounput noinput

%%
[\t ]+ ; /* ignore whitespace */;

is     |
am     |
are    |
were   |
was    |
be     |
being  |
been   |
do     |
does   |
did    |
will   |
would  |
should |
can    |
could  |
has    |
have   |
had    |
go     { printf("%s: is a verb\n", yytext); }

[a-zA-Z]+ { printf("%s: don't recognize, might be a noun\n", yytext); }

.|\n	  ;/* normal default anyway */ 
%%

