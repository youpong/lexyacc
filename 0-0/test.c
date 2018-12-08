#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "main.h"
#include "test.h"

int
test_setup(void)
{
  return 0;
}

int
test_teardown(void)
{
  return 0;
}

FILE *yyin;
char *word;
int main(int argc, char* argv[]) {
  CU_pSuite suite;
  int failures;

  CU_initialize_registry(); /* 初期化 */
  suite = CU_add_suite("func", test_setup, test_teardown);
  CU_add_test(suite, "NULL file", test_func_000);
  CU_add_test(suite, "one line", test_func_001);
  CU_add_test(suite, "end", test_func_002);
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  failures = CU_get_number_of_failures();
  CU_cleanup_registry(); /* 後始末 */

  return failures==0?EXIT_SUCCESS:EXIT_FAILURE;
}
