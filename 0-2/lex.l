%{
#include "y.tab.h"
#include "main.h"
#include <string.h>
%}

%option nounput noinput

%%
[ \t\n]+  ; /* ignore white space */
end       { return 0; }
[a-zA-Z]+ { yylval.word = strdup(yytext); return WORD; }
.         { return yytext[0]; }
%%
