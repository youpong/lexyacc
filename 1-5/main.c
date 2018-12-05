#include "lex.yy.h"
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char* argv[])
{
  int val;
  
  while((val = yylex()) != 0)
    printf("value is %d\n", val);

  return EXIT_SUCCESS;
}
