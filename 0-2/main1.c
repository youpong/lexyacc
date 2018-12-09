#include "main.h"
#include "lex.yy.h"
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>

int cnt;

int main(int argc, char *argv[]) {
  yyin = stdin;
  while(!feof(yyin))
    yyparse();

  printf("\n");

  return EXIT_SUCCESS;
}
