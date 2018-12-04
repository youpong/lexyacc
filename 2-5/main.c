#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.yy.h"
#include "main.h"

char **targv;  /* remember arguments */
char **arglim; /* end of arguments */

unsigned int fname;
unsigned int verbose;
char *progName;

int
main(int argc, char* argv[])
{
  progName = *argv;
  targv = argv+1;
  arglim = argv+argc;
  yylex();
  if(fname < 2) {
    printf("No filename given\n");
  }

  return EXIT_SUCCESS;
}
