/**
 * @file hcl_bool.c
 * @brief Implementation of HCL bool type
 * @author nukosuke
 */
#include <hcl/bool.h>

struct hcl_bool *hcl_bool_new (bool b)
{
  struct hcl_bool *b = (struct hcl_bool *) malloc (sizeof (struct hcl_bool));
  b->b = b;
  return b;
}
