/**
 * @file hcl_symtbl.h
 * @brief HCL symbol table
 * @author nukosuke
 */
#ifndef LIBHCL_HCL_SYMTBL_H
#define LIBHCL_HCL_SYMTBL_H

enum hcl_type {
  HCL_STRING_T,
  HCL_NUMBER_T,
  HCL_BOOL_T,
  HCL_LIST_T,
  HCL_MAP_T,
  HCL_OBJECT_T,
  HCL_TUPLE_T,
};

struct hcl_symtbl_ent
{
  char *name;
  void *addr;
  enum hcl_type type;
};

struct hcl_symtbl
{
  struct hcl_symtbl_ent *ent;
};

struct hcl_symtbl_ent *hcl_symtbl_ent_new (void);
struct hcl_symtbl *hcl_symtbl_new (void);

void hcl_symtbl_ent_free (struct hcl_symtbl_ent *);
void hcl_symtbl_free (struct hcl_symtbl *);

int hcl_symtbl_setent (struct hcl_symtbl_ent *, struct hcl_symtbl *);
struct hcl_symtbl_ent *hcl_symtbl_getent ();

#endif /* LIBHCL_HCL_SYMTBL */
