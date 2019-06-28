/**
 * @file test_hcl_list.c
 * @brief Test of HCL list type
 * @author nukosuke
 */
#include <check.h>
#include <hcl/list.h>

START_TEST (test_hcl_list_alloc)
{
  struct hcl_list *list = hcl_list_new ();

  hcl_list_free (list);
}
END_TEST

Suite *hcl_list_suite (void)
{
  Suite *suite = suite_create ("hcl_list");
  TCase *tcase = tcase_create ("alloc");

  tcase_add_test (tcase, test_hcl_list_alloc);
  suite_add_tcase (suite, tcase);

  return suite;
}

int main (void)
{
  SRunner *runner = srunner_create (hcl_list_suite ());

  srunner_run_all (runner, CK_NORMAL);
  int failed = srunner_ntests_failed (runner);
  return failed;
}
