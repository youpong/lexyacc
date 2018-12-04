%{
#include "main.h"
%}

%option nounput noinput

%s FNAME

%%
[ ]+         ; /* ignore blanks */

<FNAME>[^ ]+ { printf("use file %s\n", yytext); BEGIN 0; fname = 2; }

-h           |
"-?"         |
-help        { printf("usage is: %s [-help | -h | -? ] [-verbose | -v]"
      	              " [(-file| -f) filename]\n", progName);
             }
	     
-v           |
-verbose     { printf("verbose mode is on\n"); verbose = 1; }

-f           |
-file        { BEGIN FNAME; fname = 1; }

[^ ]+        ECHO;	  
%%
