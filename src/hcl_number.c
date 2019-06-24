/**
 * @file hcl_number.c
 * @brief Implementation of HCL number type
 * @author nukosuke
 */
#include <stdlib.h>
#include <hcl/number.h>

/**
 * Allocator of HCL number type
 */
struct hcl_number *hcl_number_new (void)
{
  struct hcl_number *num = (struct hcl_number *) malloc (sizeof (struct hcl_number));
  return num;
}

/**
 * Destructor of HCL number type
 */
void hcl_number_free (struct hcl_number *num)
{
  free (num);
}
