%{
#include <stdio.h>
#include <stdlib.h>
#include "word.h"

#ifndef DEBUG
#define DEBUG 0
#endif

int debug = DEBUG;
%}

%option nounput noinput

%%
[ \t]+	; /* ignore white space */

[0-9]+	        |
[0-9]+\.[0-9]+	|
\.[0-9]+	{ if(debug)printf("%s: is a number\n", yytext);
		   return NUMBER;
		}
		
#.*		{ return COMMENT; }

\"[^"\n]*\"     |
\"[^"\n]*	{ return TEXT; }

[a-zA-Z][a-zA-Z0-9]* { return COMMAND; }

\n		     { return '\n'; }
.		     ; /* ignore else */	     
%%