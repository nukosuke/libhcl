/**
 * @file test_hcl_parser.c
 * @brief Test of HCL parser
 * @author nukosuke
 */
#include <check.h>
#include <hcl.h>

START_TEST (test_hcl_parse)
{
}
END_TEST

Suite *hcl_parser_suite (void)
{
  Suite *suite = suite_create ("hcl_parser");
  TCase *tcase = tcase_create ("parse");

  tcase_add_test (tcase, test_hcl_parse);
  suite_add_tcase (suite, tcase);

  return suite;
}

int main (void)
{
  SRunner *runner = srunner_create (hcl_parser_suite ());

  srunner_run_all (runner, CK_NORMAL);
  int failed = srunner_ntests_failed (runner);
  return failed;
}
