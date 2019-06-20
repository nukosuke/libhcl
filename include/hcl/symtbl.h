/**
 * @file symtbl.h
 * @brief HCL symbol table
 * @author nukosuke
 */
#ifndef LIBHCL_HCL_SYMTBL_H
#define LIBHCL_HCL_SYMTBL_H
#include <stddef.h> // size_t

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

  // TODO: list
};

struct hcl_symtbl
{
  struct hcl_symtbl_ent **ent;
  struct hcl_symtbl_ent **cursor;
  size_t size;
};

struct hcl_symtbl *hcl_symtbl_new (size_t);
// TODO realloc funcs
void hcl_symtbl_free (struct hcl_symtbl *);

int hcl_symtbl_addent (struct hcl_symtbl *, char *, void *, enum hcl_type);
struct hcl_symtbl_ent *hcl_symtbl_getent (void);

void hcl_symtbl_print (struct hcl_symtbl *);

static struct hcl_symtbl_ent *hcl_symtbl_ent_new (char *, void *, enum hcl_type);
static void hcl_symtbl_ent_free (struct hcl_symtbl_ent *);

#endif /* LIBHCL_HCL_SYMTBL */
