/**
 * @file object.h
 * @brief HCL hash table
 * @author nukosuke
 */
#ifndef LIBHCL_HCL_OBJECT_H
#define LIBHCL_HCL_OBJECT_H
#include <stddef.h> // size_t
#include <hcl/types.h>

struct hcl_object_ent
{
  char *name;
  void *addr;
  enum hcl_type type;
  struct hcl_object_ent *next;
};

struct hcl_object
{
  struct hcl_object_ent **ent;
  struct hcl_object_ent **cursor;
  size_t size;
};

struct hcl_object *hcl_object_new (size_t);
// TODO realloc funcs
void hcl_object_free (struct hcl_object *);

int hcl_object_addent (struct hcl_object *, char *, void *, enum hcl_type);
struct hcl_object_ent *hcl_object_getent (char *);

void hcl_object_print (struct hcl_object *);

static struct hcl_object_ent *hcl_object_ent_new (char *, void *, enum hcl_type);
static void hcl_object_ent_free (struct hcl_object_ent *);

#endif /* LIBHCL_HCL_OBJECT */
