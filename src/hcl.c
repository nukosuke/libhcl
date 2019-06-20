/**
 * @file hcl.c
 * @brief Implementation of fundamental functions
 * @author nukosuke
 */
#include <stdlib.h>
#include <hcl.h>
#include <hcl/types.h>

/**
 * Allocator of HCL config object
 */
struct hcl_t *hcl_new (void)
{
  struct hcl_t *hcl = (struct hcl_t *) malloc (sizeof (struct hcl_t));
  return hcl;
}

/**
 * Destructor of HCL config object
 *
 * @param hcl Pointer of HCL config object
 */
void hcl_free (struct hcl_t *hcl)
{
  if (hcl != NULL)
    free (hcl);
}

/**
 * Initializer of HCL config object
 *
 * @param hcl Pointer of HCL config object
 * @return Status of initialization
 */
int hcl_init (struct hcl_t *hcl)
{
  return 1;
}

/**
 * @param hcl HCL config object to evaluate
 * @return The eval status
 */
static int hcl_eval (struct hcl_t *hcl)
{
  return 1;
}
