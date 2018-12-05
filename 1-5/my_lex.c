#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "word.h"

/*
 * 0: end
 * NUMBER, COMMENT, TEXT, COMMAND: type
 * c: unknown
 */
int
yylex(void)
{
  int c;

  while((c = getchar()) == ' ' || c == '\t')
    ;

  if(c == EOF)
    return 0;

  /* number 
   * [0-9]+|
   * [0-9]+\.[0-9]* 
   */
  if(isdigit(c)) { 
    while ((c = getchar()) != EOF && isdigit(c))
      ;
    if(c == '.')
      while((c=getchar()) != EOF && isdigit(c))
	;
    ungetc(c, stdin);
    return NUMBER;
  }

  /* number
   * \.[0-9]+
   */
  if(c == '.') { /* number */
    int type = c;
    while ((c = getchar()) != EOF && isdigit(c))
      type = NUMBER;
    ungetc(c, stdin);
    return type;
  }
  
  if(c == '#') { /* comment */
    while((c = getchar()) != EOF && c != '\n')
      ;
    ungetc(c, stdin);
    return COMMENT;
  }
  if(c == '"') { /* literal text */
    while((c = getchar()) != EOF &&
	  c != '"' && c != '\n')
      ;
    if(c == '\n')
      ungetc(c, stdin);
    return TEXT;
  }
  
  if( isalpha(c) ) { /* check to see if it is a command */
    while((c = getchar()) != EOF && isalnum(c))
      ;
    ungetc(c, stdin);
    return COMMAND;
  }
  
  return c;
}
