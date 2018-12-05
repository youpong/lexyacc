#include "lex.yy.h"
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (yyin == NULL) {
    yyin = stdin;
  }
  while (!feof(yyin)) {
    yyparse();
  }
  return EXIT_SUCCESS;
}

int yyerror(char *s) {
  fprintf(stderr, "%s\n", s);
  return 0;
}
