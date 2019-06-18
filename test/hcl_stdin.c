#include <stdio.h>
#include <hcl.h>

int main (void)
{
  struct hcl_t *hcl = hcl_new ();

  if (hcl_init (hcl))
    {
      fprintf(stderr, "[W] hcl_init (): failed to initialize HCL interpreter.\n");
      fprintf(stderr, "    Variable reference and Function call will be fail.\n");
    }

  hcl_parse (stdin, hcl);
  hcl_free (hcl);

  return 0;
}
