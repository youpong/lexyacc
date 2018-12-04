%{
#include "main.h"
unsigned long int charCount = 0;
unsigned long int wordCount = 0;
unsigned long int lineCount = 0;
%}

%option nounput noinput

word [^ \t\n]+
eol \n
%%
{word}	{ wordCount++; charCount += yyleng; }
{eol}	{ lineCount++; charCount++; }
. 	{ charCount++; }
%%
