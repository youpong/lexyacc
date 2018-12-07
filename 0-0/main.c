#include "main.h"
#include "lex.yy.h"
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>

int cnt;

int main(int argc, char *argv[]) {

  for (int i = 1; i < argc; i++) {
    FILE *file = fopen(argv[i], "r");
    if (file == NULL) {
      fprintf(stderr, "file(%s) cannot open.\n", argv[i]);
      continue;
    }
    yyin = file;

    cnt = 0;
    yyparse();
    fclose(yyin);
    printf("\n");
  }

  return EXIT_SUCCESS;
}
