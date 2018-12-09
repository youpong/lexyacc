#include "lex.yy.h"
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>

int yydebug = 0; /* 0..off, 1..on */

int main(int argc, char *argv[]) {
  yyin = stdin;
  yyparse();

  return EXIT_SUCCESS;
}
