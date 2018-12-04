#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "main.h"
#include "test.h"

int
test_setup(void)
{
  code = 0;
  comments = 0;
  whiteSpace = 0;
  
  return 0;
}

int
test_teardown(void)
{
  return 0;
}

int
main(int argc, char* argv[])
{
  CU_pSuite suite;
  int failures;

  CU_initialize_registry(); /* 初期化 */
  suite = CU_add_suite("yylex", NULL, NULL);
  CU_add_test(suite, "0", test_yylex_000);
  CU_add_test(suite, "1", test_yylex_001);
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  failures = CU_get_number_of_failures();
  CU_cleanup_registry(); /* 後始末 */

  return failures==0?EXIT_SUCCESS:EXIT_FAILURE;
}
