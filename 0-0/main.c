#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "y.tab.h"
#include "lex.yy.h"

int
main(int argc, char* argv[])
{
  while(!feof(yyin))
    yyparse();

  return EXIT_SUCCESS;
}

