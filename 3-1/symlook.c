#include <string.h>
#include <stdlib.h>
#include "calc.h"

/* look up a symbol table entry, ad if not present */
struct symtab *
symlook(char *s)
{
  struct symtab *sp;

  for(sp = symtab; sp < &symtab[NSYMS]; sp++) {
    /* is it already here ? */
    if(sp->name && !strcmp(sp->name, s)) 
      return sp;

    /* is it free */
    if(!sp->name) {
      sp->name = strdup(s);
      return sp;
    }
    /* otherwise continue to next */
  }
  yyerror("Too many symbols");
  exit(1); /* cannot continue */
}
