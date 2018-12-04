%{
#include <stdio.h>
%}

%option nounput noinput

%s MAGIC

%%
magic     BEGIN MAGIC;
<MAGIC>.+ { BEGIN 0; printf("Magic:"); ECHO; }
.+        ECHO;
%%
