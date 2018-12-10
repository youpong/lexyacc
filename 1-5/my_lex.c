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
  char *p;
  yytext = (char *)malloc(sizeof(char) * 100);

start:
  p = yytext;

  /* [ \t]+ ;ignore white space */
  while ((c = getc(yyin)) == ' ' || c == '\t')
    ;

  if (c == EOF)
    return 0;

  /* number(1 of 2)
   * [0-9]+         |
   * [0-9]+\.[0-9]+ |
   */
  if (isdigit(c)) {
    *p++ = c;
    while ((c = getc(yyin)) != EOF && isdigit(c))
      *p++ = c;
    if (c == '.') {
      *p++ = c;
      if ((c = getc(yyin)) == EOF || !isdigit(c)) {
        ungetc(c, yyin);
        ungetc(c, yyin);
        *--p = '\0';
        return NUMBER;
      }
      *p++ = c;
      while ((c = getc(yyin)) != EOF && isdigit(c))
        *p++ = c;
    }
    ungetc(c, yyin);
    *p = '\0';
    return NUMBER;
  }

  /* number(2 of 2)
   * \.[0-9]+ reutnr NUMBER;
   */
  if (c == '.') {
    int type = c;
    *p++ = c;
    while ((c = getc(yyin)) != EOF && isdigit(c)) {
      type = NUMBER;
      *p++ = c;
    }
    ungetc(c, yyin);
    *p = '\0';
    return type;
  }

  /* #.* return COMMENT */
  if (c == '#') { /* comment */
    while ((c = getc(yyin)) != EOF && c != '\n')
      ;
    ungetc(c, yyin);
    return COMMENT;
  }

  /* \"[^"\n]*\" return TEXT */
  while (c == '"') {
    *p++ = c;
    while ((c = getc(yyin)) != EOF && c != '"' && c != '\n')
      *p++ = c;
    if (c == '"') {
      *p++ = c;
      *p = '\0';
      return TEXT;
    }

    /*
     * '"' で閉じられていないので、'"'以後読み込んだデータを積み直して
     * 最初からやり直す
     */
    *p++ = c;
    *p = '\0';
    // printf("D: push back(%s)\n", yytext);
    while (p - yytext > 1) {
      ungetc(*--p, yyin);
    }

    goto start;
  }

  /* check to see if it is a command */
  if (isalpha(c)) {
    while ((c = getc(yyin)) != EOF && isalnum(c))
      ;
    ungetc(c, yyin);
    return COMMAND;
  }

  /* \n return '\n'; */
  if (c == '\n')
    return c;

  goto start;
}
