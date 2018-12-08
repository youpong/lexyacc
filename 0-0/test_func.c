#include <CUnit/CUnit.h>
#include "main.h"
#include "test.h"
#include "lex.yy.h"

static FILE *open_file(char *);

/* null file */
void test_func_000() {
  yyin = open_file("sample/0.input");
  CU_ASSERT_EQUAL(yylex(), 0);
  fclose(yyin);
}

/* one line file */
void test_func_001() {
  int ret;
  yyin = open_file("sample/1.input");
  CU_ASSERT_EQUAL(yylex(), SYMB);  
  while((ret = yylex()) != 0)
    ;
  CU_ASSERT_EQUAL(ret, 0);
  fclose(yyin);
}

/* end */
void test_func_002() {
  yyin = open_file("sample/2.input");

  CU_ASSERT_EQUAL(yylex(), SYMB);
  CU_ASSERT_STRING_EQUAL(word, "start");    
  CU_ASSERT_EQUAL(yylex(), 0);
  CU_ASSERT_EQUAL(yylex(), SYMB);
  CU_ASSERT_STRING_EQUAL(word, "end");      

  fclose(yyin);
}

static FILE *open_file(char *path) {
  FILE *file = fopen(path, "r");
  if(file == NULL) {
    fprintf(stderr, "cannot open file\n");
    exit(EXIT_FAILURE);
  }
  return file;
}

