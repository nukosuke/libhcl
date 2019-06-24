/**
 * @file hcl_bool.c
 * @brief Implementation of HCL bool type
 * @author nukosuke
 */
#include <stdlib.h>
#include <hcl/bool.h>

/**
 * Allocator of HCL bool type
 *
 * @return Pointer of HCL bool type
 */
struct hcl_bool *hcl_bool_new (bool b)
{
  struct hcl_bool *bl = (struct hcl_bool *) malloc (sizeof (struct hcl_bool));
  bl->b = b;
  return bl;
}

/**
 * Destructor of HCL bool type
 *
 * @param b HCL bool type
 */
void hcl_bool_free (struct hcl_bool *b)
{
  free (b);
}
