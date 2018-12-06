#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "y.tab.h"
#include "lex.yy.h"

int cnt = 0;
int
main(int argc, char* argv[])
{
  yyin = stdin;
  while(!feof(yyin))
    yyparse();

  return EXIT_SUCCESS;
}
