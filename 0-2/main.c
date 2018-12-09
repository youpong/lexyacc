#include "main.h"
#include "lex.yy.h"
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>

int cnt;

int main(int argc, char *argv[]) {
  /* 
   * 規則にマッチしたあと、yyparse() は終了し、状態が初期に戻る。
   */
  yyparse();
  yyparse();

  return EXIT_SUCCESS;
}
