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
  }
  if (c == '.') {
    *p++ = c;
    while ((c = getc(yyin)) != EOF && isdigit(c)) 
      *p++ = c;
  }

  // . の後が数字でなければ . まで遡って unput
  if(p > yytext && *(p-1) == '.') {
    ungetc(c, yyin);
    if(strcmp(yytext, ".") == 0)
      return yytext[0]; 
    ungetc( *--p, yyin);
    *p = '\0';
    return NUMBER;
  }
  
  // 終端処理と unget してから return  
  if(p > yytext) {
    *p = '\0';
    ungetc(c, yyin);
    return NUMBER;
  }

  /* #.* return COMMENT */
  if (c == '#') { /* comment */
    while ((c = getc(yyin)) != EOF && c != '\n')
      ;
    ungetc(c, yyin);
    return COMMENT;
  }

  /* \"[^"\n]*\" return TEXT */
  if (c == '"') {
    *p++ = c;
    while ((c = getc(yyin)) != EOF && c != '"' && c != '\n')
      *p++ = c;
    if (c == '"') {
      *p++ = c;
      *p = '\0';
      return TEXT;
    }

    /*
     * '"' で閉じられていないので、'"'以後読み込んだデータを積み直す
     */
    *p++ = c;
    while (p - yytext > 1) {
      ungetc(*--p, yyin);
    }

    return yytext[0];
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
