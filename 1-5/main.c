#include "lex.yy.h"
#include "word.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int val;
  char *word_type[] = { "NUMBER", "COMMENT", "TEXT", "COMMAND", };

  while ((val = yylex()) != 0) {
    if(val >= NUMBER && val <= COMMAND )
      printf("%s", word_type[val - NUMBER]);
    else
      printf("%d", val);
    
    if(val == NUMBER) {
      printf("(%s)", yytext);
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}
