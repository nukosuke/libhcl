/**
 * @file hcl_symtbl.c
 * @brief Symbol table printer for manual testing
 * @author nukosuke
 */
#include <stdio.h>

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

  // TODO
  // new sym hashtable
  // parse
  // dump the result

  fclose (fp);
  return 0;
}
