#include <stdio.h>
#include <stdlib.h>
#include "lex.yy.h"
#include "main.h"

int
main(int argc, char* argv[])
{
  yylex();
  printf("code: %d, comments: %d, white space %d\n",
	 code, comments, whiteSpace);
  
  return EXIT_SUCCESS;
}
