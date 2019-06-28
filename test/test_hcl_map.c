/**
 * @file test_hcl_map.c
 * @brief Test of HCL map type
 * @author nukosuke
 */
#include <check.h>
#include <hcl/map.h>

START_TEST (test_hcl_map_alloc)
{
}
END_TEST

Suite *hcl_map_suite (void)
{
  Suite *suite = suite_create ("hcl_map");
  TCase *tcase = tcase_create ("alloc");

  tcase_add_test (tcase, test_hcl_map_alloc);
  suite_add_tcase (suite, tcase);

  return suite;
}

int main (void)
{
  SRunner *runner = srunner_create (hcl_map_suite ());

  srunner_run_all (runner, CK_NORMAL);
  int failed = srunner_ntests_failed (runner);
  return failed;
}
