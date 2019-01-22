#include "main.h"
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  yyparse();
  return EXIT_SUCCESS;
}

_Noreturn int yyerror(char *msg) {
  fprintf(stderr, "%s\n", msg);
  exit(EXIT_FAILURE);
}
