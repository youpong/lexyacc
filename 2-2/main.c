#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "lex.yy.h"

int
main(int argc, char* argv[])
{
  yylex();
  printf("%d %d %d\n", lineCount, wordCount, charCount);

  return EXIT_SUCCESS;
}
