#include <stdlib.h>
#include <CUnit/CUnit.h>
#include "main.h"
#include "test.h"

FILE *yyin;

void
test_yylex_000(void)
{
  FILE *file;

  test_setup();
  file = fopen("sample.input", "r");
  if(!file) {
    fprintf(stderr, "couldn't open file\n");
    exit(EXIT_FAILURE);
  }
  yyin = file;
  yylex();
  fclose(yyin);
  
  CU_ASSERT_EQUAL( code,       1 );
  CU_ASSERT_EQUAL( comments,   0 );
  CU_ASSERT_EQUAL( whiteSpace, 0 );
}

void
test_yylex_001(void)
{
  FILE *file;

  test_setup();
  file = fopen("sample2.input", "r");
  if(!file) {
    fprintf(stderr, "couldn't open file\n");
    exit(EXIT_FAILURE);
  }

  yyin = file;
  yylex();
  fclose(yyin);
  
  CU_ASSERT_EQUAL( code,       0 );
  CU_ASSERT_EQUAL( comments,   1 );
  CU_ASSERT_EQUAL( whiteSpace, 0 );
}
