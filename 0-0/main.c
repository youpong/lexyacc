#include "main.h"
#include "lex.yy.h"
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>

int cnt = 0;
int main(int argc, char *argv[]) {
  yyin = stdin;
  while (!feof(yyin))
    yyparse();

  return EXIT_SUCCESS;
}
