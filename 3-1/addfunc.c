#include "calc.h"

void
addfunc(char *name, double (*func)())
{
  struct symtab *sp = symlook(name);
  sp->funcptr = func;
}

