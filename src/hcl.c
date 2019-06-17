/**
 * @file hcl.c
 * @brief Implementation of fundamental functions
 */
#include <hcl.h>

hcl_t *hcl_new (void)
{
  return 0;
}

void hcl_free (hcl_t *hcl)
{
}

void hcl_init (hcl_t *hcl)
{
}

int hcl_parse (FILE *fptr, hcl_t *hcl)
{
  extern int yyparse (void);
  extern FILE *yyin;

  yyin = fptr;
  if (yyparse())
    {
      return 1;
    }
  return 0;
}
