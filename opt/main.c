#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "y.tab.h"

int
main(int argc, char* argv[])
{
  yyparse();
  return EXIT_SUCCESS;
}

_Noreturn int yyerror(char *msg) {
  fprintf(stderr, "%s\n", msg);
  exit(EXIT_FAILURE);
}
