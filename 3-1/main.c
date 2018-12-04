#include <math.h>
#include <stdlib.h>
#include "y.tab.h"
#include "calc.h"

int
main(int argc, char *argv[])
{
  addfunc("sqrt", sqrt);
  addfunc("exp",  exp);
  addfunc("log",  log);
  addfunc("pow",  pow);

  yyparse();

  return EXIT_SUCCESS;
}
