/**
 * @file hcl_symtbl.c
 * @brief Symbol table printer for manual testing
 * @author nukosuke
 */
#include <stdio.h>
#include <hcl.h>
#include <hcl/symtbl.h>

#define SYMTBL_DEFAULT_SIZE 2048

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
      fprintf (stderr, "[E] Failed to open file: %s\n", argv[1]);
      return 1;
    }

  // TODO:
  // new sym hashtable

  struct hcl_t *hcl = hcl_new ();
  if (hcl_init (hcl))
    {
      fprintf (stderr, "[W] hcl_init (): failed to initialize HCL interpreter.\n");
      fprintf (stderr, "    Variable reference and Function call will be fail.\n");
    }

  // TODO: move to under hcl_parse ()
  struct hcl_symtbl *tbl = hcl_symtbl_new (SYMTBL_DEFAULT_SIZE);
  hcl_symtbl_addent (tbl, "hoge", "hoge", HCL_STRING_T);
  hcl_symtbl_addent (tbl, "fuga", hcl, HCL_NUMBER_T);
  hcl_symtbl_addent (tbl, "piyo", hcl, HCL_BOOL_T);
  hcl_symtbl_print (tbl);
  hcl_symtbl_free (tbl);

  hcl_parse (fp, hcl);
  // TODO: dump the result

  hcl_free (hcl);
  fclose (fp);
  return 0;
}
