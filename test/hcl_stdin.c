#include <stdio.h>
#include <hcl.h>

int main (void)
{
  hcl_t *hcl = hcl_new ();
  hcl_init (hcl);
  hcl_parse (stdin, hcl);
  hcl_free (hcl);
  return 0;
}
