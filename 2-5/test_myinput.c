#include <stdlib.h>
#include <CUnit/CUnit.h>
#include "main.h"
#include "test.h"

char **targv;
char **arglim;

char *progName;
unsigned int verbose;


void
test_myinput_000(void)
{
  char *temp[] = {"-d", "parse.y"};
  char buf[512];
  int max = 512;
  int ret;

  targv = temp;
  arglim = temp+2;
  
  ret = myinput(buf, max);
  CU_ASSERT_EQUAL(ret, 3);
  CU_ASSERT_NSTRING_EQUAL(buf, "-d ", 3);
  ret = myinput(buf, max);
  CU_ASSERT_EQUAL(ret, 8);
  CU_ASSERT_NSTRING_EQUAL(buf, "parse.y ", 8);
  ret = myinput(buf, max);
  CU_ASSERT_EQUAL(ret, 0);
}

void
test_myinput_001(void)
{
  char *temp[] = {"pa", "-"};
  char buf[1];
  int max = 1;
  int ret;

  targv = temp;
  arglim = temp+2;

  ret = myinput(buf, max);
  CU_ASSERT_EQUAL(ret, 0);  
}

void
test_myinput_002(void)
{
  char *temp[] = {"pa", "-"};
  char buf[2];
  int max = 2;
  int ret;

  targv = temp;
  arglim = temp+2;

  ret = myinput(buf, max);
  CU_ASSERT_EQUAL(ret, 1);
  CU_ASSERT_NSTRING_EQUAL(buf, "p", 1);
  
  ret = myinput(buf, max);
  CU_ASSERT_EQUAL(ret, 2);
  CU_ASSERT_NSTRING_EQUAL(buf, "a ", 2);
  
  ret = myinput(buf, max);
  CU_ASSERT_EQUAL(ret, 2);
  CU_ASSERT_NSTRING_EQUAL(buf, "- ", 2);
  
  ret = myinput(buf, max);
  CU_ASSERT_EQUAL(ret, 0);
}

void
test_myinput_003(void){
  char *temp[] = {"parse.y"};
  char buf[0];
  int max = 0;
  int ret;

  targv = temp;
  arglim = temp+2;
  
  ret = myinput(buf, max);
  CU_ASSERT_EQUAL(ret, 0);
}

void
test_myinput_004(void)
{
  char *temp[] = {"", "parse.y"};
  char buf[512];
  int max = 512;
  int ret;

  targv = temp;
  arglim = temp+2;
  
  ret = myinput(buf, max);
  CU_ASSERT_EQUAL(ret, 1);
  CU_ASSERT_NSTRING_EQUAL(buf, " ", 1);

  ret = myinput(buf, max);
  CU_ASSERT_EQUAL(ret, 8);
  CU_ASSERT_NSTRING_EQUAL(buf, "parse.y ", 8);  
}
