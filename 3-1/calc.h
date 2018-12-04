/*
 * Header for calculator program
 */

#define NSYMS 20 /* maximum number of symbols */

struct symtab {
  char *name;
  double (*funcptr)();
  double dval;
  char   *sval;
} symtab[NSYMS];

struct symtab *symlook();
void addfunc(char *, double (*)());
int yyerror(char *);
