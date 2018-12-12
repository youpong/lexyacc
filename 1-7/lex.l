%{
#include "main.h"
%}
%option nounput noinput
%s COMMENT COMMENT2
%%
"/*"                { BEGIN COMMENT;       ECHO;}
<COMMENT>"*/"       { BEGIN 0; comments++; ECHO; printf("\n");}
"//"                { BEGIN COMMENT2;      ECHO;}
<COMMENT2>\n        { BEGIN 0; comments++; ECHO;}
<COMMENT,COMMENT2>. {                      ECHO;}
<COMMENT>\n         {          comments++; ECHO;}
.|\n		    ;
%%
