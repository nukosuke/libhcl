/**
 * @file hcl_tuple.c
 * @brief Implementation of HCL tuple type
 * @author nukosuke
 */
#include <stdlib.h>
#include <hcl/tuple.h>

struct hcl_tuple *hcl_tuple_new (void)
{
  struct hcl_tuple *tuple = (struct hcl_tuple *) malloc (sizeof (struct hcl_tuple));
  return tuple;
}

void hcl_tuple_free (struct hcl_tuple *tuple)
{
  free (tuple);
}
