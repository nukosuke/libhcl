/**
 * @file hcl.c
 * @brief Implementation of fundamental functions
 * @author nukosuke
 */
#include <hcl.h>

struct hcl_t *hcl_new (void)
{
  return 0;
}

void hcl_free (struct hcl_t *hcl)
{
}

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
