%{
#include "main.h"
unsigned int charCount = 0;
unsigned int wordCount = 0;
unsigned int lineCount = 0;
%}

%option nounput noinput

word [^ \t\n]+
eol \n
%%
{word}	{ wordCount++; charCount += yyleng; }
{eol}	{ lineCount++; charCount++; }
. 	{ charCount++; }
%%
