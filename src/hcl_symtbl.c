/**
 * @file hcl_symtbl.c
 * @brief Implementation of HCL symbol table
 * @author nukosuke
 */
#include "hcl_symtbl.h"

struct hcl_symtbl_ent *hcl_symtbl_ent_new (void)
{
  return 0;
}

struct hcl_symtbl *hcl_symtbl_new (void)
{
  return 0;
}

void hcl_symtbl_ent_free (struct hcl_symtbl_ent *ent)
{
}

void hcl_symtbl_free (struct hcl_symtbl *tbl)
{
}

int hcl_symtbl_setent (struct hcl_symtbl_ent *ent, struct hcl_symtbl *tbl)
{
  return 1;
}

struct hcl_symtbl_ent *hcl_symtbl_getent ()
{
  return 0;
}
