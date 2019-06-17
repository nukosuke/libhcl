/**
 * @file hcl.c
 * @brief Implementation of fundamental functions
 * @author nukosuke
 */
#include <hcl.h>

hcl_t *hcl_new (void)
{
  return 0;
}

void hcl_free (hcl_t *hcl)
{
}

int hcl_init (hcl_t *hcl)
{
  return 1;
}

/**
 * @param hcl HCL config object to evaluate
 * @return The eval status
 */
static int hcl_eval (hcl_t *hcl)
{
}
