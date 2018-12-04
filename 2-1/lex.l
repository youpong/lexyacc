%{
#include <stdio.h>
#include <stdlib.h>
%}
%option nounput noinput
%%
[\n\t ]	; /* ignore white space */

-?(([0-9]+)|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?) {
	printf("%s: number\n", yytext);
	}

\"[^"]*\"	{ printf("%s: text\n", yytext); }

#.*     |		
.	; /* ignore */
%%
int
main(int argc, char* argv[])
{
	yylex();
	return EXIT_SUCCESS;
}
