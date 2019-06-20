/**
 * @file hcl_symtbl.c
 * @brief Implementation of HCL symbol table
 * @author nukosuke
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memset
#include "hcl_symtbl.h"

/**
 * Symbol table allocator
 *
 * @param size default size of the table
 * @return Pointer of allocated table
 */
struct hcl_symtbl *hcl_symtbl_new (size_t size)
{
  struct hcl_symtbl *tbl = (struct hcl_symtbl *) malloc (sizeof (struct hcl_symtbl));
  if (tbl == NULL)
    return NULL;

  tbl->ent = (struct hcl_symtbl_ent **) malloc (sizeof (struct hcl_symtbl_ent *) * size);
  if (tbl->ent == NULL)
    {
      free (tbl);
      return NULL;
    }

  // Zero fill to terminate iteration by NULL comparison
  memset (tbl->ent, 0, sizeof (*tbl->ent));
  tbl->size = size;

  return tbl;
}

/**
 * Symbol table destructor
 *
 * @param tbl Pointer of the table to be deleted
 */
void hcl_symtbl_free (struct hcl_symtbl *tbl)
{
  for (struct hcl_symtbl_ent **ent = tbl->ent; ent != NULL; ent++)
    free (*ent);

  free (tbl->ent);
  free (tbl);
}

int hcl_symtbl_addent (struct hcl_symtbl_ent *ent, struct hcl_symtbl *tbl)
{
  return 1;
}

struct hcl_symtbl_ent *hcl_symtbl_getent (void)
{
  return 0;
}

void hcl_symtbl_print (struct hcl_symtbl *tbl)
{
  for (struct hcl_symtbl_ent **ent = tbl->ent; ent != NULL; ent++)
    {
      printf ("type: %d\t", (*ent)->type);
      printf ("name: %s\t", (*ent)->name);
      printf ("addr: %p\n", (*ent)->addr);
    }
}
