#include "lex.yy.h"
#include "word.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int val;
  int verbose = 0;
  FILE *file;  
  char *word_type[] = {
      "NUMBER",
      "COMMENT",
      "TEXT",
      "COMMAND",
  };

  if (argc > 1 && strcmp(argv[1], "-v") == 0) {
    verbose = 1;
    argc--;
    argv++;
  }
  
  switch (argc) {
  case 1:
    yyin = stdin;
    break;
  case 2:
    file = fopen(argv[1], "r");
    if (file == NULL) {
      fprintf(stderr, "file cannot open\n");
      exit(EXIT_FAILURE);
    }
    yyin = file;
    break;
  default:
    fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  while ((val = yylex()) != 0) {
    if (val >= NUMBER && val <= COMMAND)
      printf("%s", word_type[val - NUMBER]);
    else
      printf("%d", val);

    if (verbose == 1 && (val == NUMBER || val == TEXT)) {
      printf("(%s)", yytext);
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}
