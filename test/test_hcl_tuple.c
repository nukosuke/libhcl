/**
 * @file test_hcl_tuple.c
 * @brief Test of HCL tuple type
 * @author nukosuke
 */
#include <check.h>
#include <hcl/tuple.h>

START_TEST (test_hcl_tuple_alloc)
{
}
END_TEST

Suite *hcl_tuple_suite (void)
{
  Suite *suite = suite_create ("hcl_tuple");
  TCase *tcase = tcase_create ("alloc");

  tcase_add_test (tcase, test_hcl_tuple_alloc);
  suite_add_tcase (suite, tcase);

  return suite;
}

int main (void)
{
  SRunner *runner = srunner_create (hcl_tuple_suite ());

  srunner_run_all (runner, CK_NORMAL);
  int failed = srunner_ntests_failed (runner);
  return failed;
}
