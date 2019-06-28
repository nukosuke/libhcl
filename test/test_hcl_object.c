/**
 * @file test_hcl_object.c
 * @brief Test of HCL object type
 * @author nukosuke
 */
#include <check.h>
#include <hcl/object.h>

START_TEST (test_hcl_object_alloc)
{
}
END_TEST

Suite *hcl_object_suite (void)
{
  Suite *suite = suite_create ("hcl_object");
  TCase *tcase = tcase_create ("alloc");

  tcase_add_test (tcase, test_hcl_object_alloc);
  suite_add_tcase (suite, tcase);

  return suite;
}

int main (void)
{
  SRunner *runner = srunner_create (hcl_object_suite ());

  srunner_run_all (runner, CK_NORMAL);
  int failed = srunner_ntests_failed (runner);
  return failed;
}
