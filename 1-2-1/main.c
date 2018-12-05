#include "main.h"
#include "lex.yy.h"
#include <stdio.h>
#include <stdlib.h>

WORD_TYPE state;

int main(int argc, char *argv[]) {
  yylex();

  return EXIT_SUCCESS;
}
