/**
 * @file hcl_tuple.c
 * @brief Implementation of HCL tuple type
 * @author nukosuke
 */
#include <stdlib.h>
#include <hcl/tuple.h>

/**
 * Allocator of HCL tuple type
 *
 * @return Pointer of HCL tuple type
 */
struct hcl_tuple *hcl_tuple_new (void)
{
  struct hcl_tuple *tuple = (struct hcl_tuple *) malloc (sizeof (struct hcl_tuple));
  return tuple;
}

/**
 * Destructor of HCL tuple type
 *
 * @param Pointer of HCL tuple type
 */
void hcl_tuple_free (struct hcl_tuple *tuple)
{
  free (tuple);
}
