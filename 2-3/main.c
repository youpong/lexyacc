#include <stdio.h>
#include <stdlib.h>
#include "lex.yy.h"
#include "main.h"

extern FILE *yyin;

int
main(int argc, char* argv[])
{
  if(argc > 1){
    FILE *file;
    file = fopen(argv[1], "r");
    if(!file) {
      fprintf(stderr, "could not open %s\n", argv[1]);
      return EXIT_FAILURE;
    }
    yyin = file;
  }
  yylex();
  printf("%d %d %d\n", lineCount, wordCount, charCount);

  return EXIT_SUCCESS;
}
