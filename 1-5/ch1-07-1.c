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

  /* number
   * [0-9]+         |
   * [0-9]+\.[0-9]+ |
   *       \.[0-9]+  return NUMBER
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

  // yytext に１文字以上設定されていれば、 NUMBER
  // または '.' を返却する
  if (p > yytext) {
    ungetc(c, yyin);

    // "." の場合。 '.' を返却
    if (p - yytext == 1 && yytext[0] == '.')
      return yytext[0];

    // おしりが '.' で終わる場合、それを unget する
    if (*(p - 1) == '.')
      ungetc(*--p, yyin);

    // 終端処理してから return
    *p = '\0';
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
