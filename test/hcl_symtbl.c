/**
 * @file hcl_symtbl.c
 * @brief Symbol table printer for manual testing
 * @author nukosuke
 */
#include <stdio.h>
#include <hcl.h>

int main (int argc, char **argv)
{
  if (argc < 2)
    {
      fprintf (stderr, "[E] Missing argument. Please specify filepath to show symbol table.\n");
      return 1;
    }

  FILE *fp;
  if ((fp = fopen (argv[1], "r")) == NULL)
    {
      fprintf(stderr, "[E] Failed to open file: %s\n", argv[1]);
      return 1;
    }

  // TODO:
  // new sym hashtable

  struct hcl_t *hcl = hcl_new ();

  if (hcl_init (hcl))
    {
      fprintf(stderr, "[W] hcl_init (): failed to initialize HCL interpreter.\n");
      fprintf(stderr, "    Variable reference and Function call will be fail.\n");
    }

  hcl_parse (fp, hcl);
  // TODO: dump the result

  hcl_free (hcl);
  fclose (fp);
  return 0;
}
