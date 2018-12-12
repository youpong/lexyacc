#include <stdio.h>
#include <stdlib.h>
#include "lex.yy.h"
#include "main.h"

int comments = 0;
int main(int argc, char **argv) {
  yylex();
  printf("comments: %d\n", comments);

  return EXIT_SUCCESS;
}
