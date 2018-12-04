#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
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

int
main(int argc, char* argv[])
{
  CU_pSuite suite;
  int failures;

  CU_initialize_registry(); /* 初期化 */
  suite = CU_add_suite("myinput", test_setup, test_teardown);
  CU_add_test(suite, "0", test_myinput_000);
  //  CU_add_test(suite, "1", test_myinput_001);
  CU_add_test(suite, "2", test_myinput_002);
  //CU_add_test(suite, "3", test_myinput_003);
  CU_add_test(suite, "4", test_myinput_004);
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  failures = CU_get_number_of_failures();
  CU_cleanup_registry(); /* 後始末 */

  return failures==0?EXIT_SUCCESS:EXIT_FAILURE;
}

