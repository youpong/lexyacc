#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "lex.yy.h"
#include "word.h"

char *yytext;
/*
 * 0: end
 * NUMBER, COMMENT, TEXT, COMMAND: type
 * c: unknown
 */
int yylex(void) {
  int c;
  yytext = (char *)malloc(sizeof(char) * 100);
  char *p = yytext;

  /* [ \t]+ ;ignore white space */
  while ((c = getchar()) == ' ' || c == '\t')
    ;

  if (c == EOF)
    return 0;

  /* number(1 of 2)
   * [0-9]+         |
   * [0-9]+\.[0-9]+ |
   */
  if (isdigit(c)) {
    *p++ = c;
    while ((c = getchar()) != EOF && isdigit(c))
      *p++ = c;
    if (c == '.') {
      *p++ = c;
      if((c = getchar()) == EOF || !isdigit(c)) {
	ungetc(c, stdin);
	ungetc(c, stdin);
	*--p = '\0';
	return NUMBER;
      }
      *p++ = c;
      while ((c = getchar()) != EOF && isdigit(c))
	*p++ = c;
    }
    ungetc(c, stdin);
    *p = '\0';
    return NUMBER;
  }

  /* number(2 of 2)
   * \.[0-9]+ reutnr NUMBER;
   */
  if (c == '.') { 
    int type = c;
    *p++ = c;
    while ((c = getchar()) != EOF && isdigit(c)) {
      type = NUMBER;
      *p++=c;
    }
    ungetc(c, stdin);
    *p = '\0';
    return type;
  }

  /* #.* return COMMENT */
  if (c == '#') { /* comment */
    while ((c = getchar()) != EOF && c != '\n')
      ;
    ungetc(c, stdin);
    return COMMENT;
  }
  /* \"[^"\n]*\" |
     \"[^"\n]*     return TEXT */
  if (c == '"') { 
    while ((c = getchar()) != EOF && c != '"' && c != '\n')
      ;
    if (c == '\n')
      ungetc(c, stdin);
    return TEXT;
  }

  if (isalpha(c)) { /* check to see if it is a command */
    while ((c = getchar()) != EOF && isalnum(c))
      ;
    ungetc(c, stdin);
    return COMMAND;
  }

  return c;
}
