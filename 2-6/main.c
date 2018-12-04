#include <stdlib.h>
#include "lex.yy.h"
#include "lex2.yy.h"

int
main(int argc, char* argv[])
{
  yylex();

  return EXIT_SUCCESS;
}
