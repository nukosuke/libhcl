/**
 * @file hcl_symtbl.c
 * @brief Implementation of HCL symbol table
 * @author nukosuke
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memset
#include <hcl/symtbl.h>

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
  tbl->cursor = tbl->ent;
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
  for (struct hcl_symtbl_ent **ent = tbl->ent; *ent != NULL; ent++)
    hcl_symtbl_ent_free (*ent);

  free (tbl->ent);
  free (tbl);
}

/**
 * Add new entry to symbol table
 *
 * @param tbl Pointer of symbol table
 * @param name The name of entry
 * @param addr Address of value data
 * @param type HCL type
 * @return Status of addition
 */
int hcl_symtbl_addent (struct hcl_symtbl *tbl, char *name, void *addr, enum hcl_type type)
{
  *tbl->cursor = hcl_symtbl_ent_new (name, addr, type);
  if (*tbl->cursor == NULL)
    return 1;

  tbl->cursor++;
  return 0;
}

struct hcl_symtbl_ent *hcl_symtbl_getent (char *name)
{
  // TODO: calc string hash and searh from list
  return 0;
}

/**
 * Print symbol table entries to stdout
 *
 * @param tbl Pointer of symbol table
 */
void hcl_symtbl_print (struct hcl_symtbl *tbl)
{
  for (struct hcl_symtbl_ent **ent = tbl->ent; *ent != NULL; ent++)
    {
      printf ("type: %d\t", (*ent)->type);
      printf ("name: %s\t", (*ent)->name);
      printf ("addr: %p\n", (*ent)->addr);
    }
}

static struct hcl_symtbl_ent *hcl_symtbl_ent_new (char *name, void *addr, enum hcl_type type)
{
  struct hcl_symtbl_ent *ent = (struct hcl_symtbl_ent *) malloc (sizeof (struct hcl_symtbl_ent));
  if (ent == NULL)
    return NULL;

  ent->name = (char *) malloc (sizeof (name));
  if (ent->name == NULL)
    {
      free (ent);
      return NULL;
    }

  strcpy (ent->name, name);
  ent->addr = addr;
  ent->type = type;

  return ent;
}

static void hcl_symtbl_ent_free (struct hcl_symtbl_ent *ent)
{
  free (ent->name);
  free (ent);
}
