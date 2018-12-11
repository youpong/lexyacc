#include "lex.yy.h"
#include "word.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

FILE *yyin;
char *yytext;

/*
 * 0: end
 * NUMBER, COMMENT, TEXT, COMMAND: type
 * c: unknown
 */
int yylex(void) {
  int c;
  yytext = NULL;

  /* [ \t]+ ;ignore white space */
  while ((c = getc(yyin)) == ' ' || c == '\t')
    ;

  if (c == EOF)
    return 0;

  /* number */
  if (c == '.' || isdigit(c)) {
    while ((c = getc(yyin)) != EOF && isdigit(c))
      ;
    if (c == '.')
      while ((c = getc(yyin)) != EOF && isdigit(c))
        ;
    ungetc(c, yyin);
    return NUMBER;
  }

  /* #.* return COMMENT */
  if (c == '#') {
    while ((c = getc(yyin)) != EOF && c != '\n')
      ;
    ungetc(c, yyin);
    return COMMENT;
  }

  /* \"[^"\n]*\" return TEXT */
  if (c == '"') {
    while ((c = getc(yyin)) != EOF && c != '"' && c != '\n')
      ;
    if (c == '\n')
      ungetc(c, yyin);
    return TEXT;
  }

  /* check to see if it is a command */
  if (isalpha(c)) {
    while ((c = getc(yyin)) != EOF && isalnum(c))
      ;
    ungetc(c, yyin);
    return COMMAND;
  }

  /* . ECHO; gleaning */
  return c;
}
