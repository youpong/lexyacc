#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "lex.yy.h"

char *word;

int main(int argc, char* argv[]) {
  int ret;
  yyin = stdin;
  while((ret = yylex()) != 0)
    printf("yylex() = %d\n", ret);
  printf("yylex() = %d\n", ret);  
  
  return EXIT_SUCCESS;
}
