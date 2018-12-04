%{
/* This example deliverately doesn't work ! */
#include <stdio.h>
%}

%option nounput noinput

%s MAGIC

%%
magic     BEGIN MAGIC;
.+        ECHO;
<MAGIC>.+ { BEGIN 0; printf("Magic:"); ECHO; }
%%
