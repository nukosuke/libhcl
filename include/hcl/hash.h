/**
 * @file hash.h
 * @brief HCL hash table
 * @author nukosuke
 */
#ifndef LIBHCL_HCL_HASH_H
#define LIBHCL_HCL_HASH_H
#include <stddef.h> // size_t
#include <hcl/types.h>

struct hcl_hash_ent
{
  char *name;
  void *addr;
  enum hcl_type type;
  struct hcl_hash_ent *next;
};

struct hcl_hash
{
  struct hcl_hash_ent **ent;
  struct hcl_hash_ent **cursor;
  size_t size;
};

struct hcl_hash *hcl_hash_new (size_t);
// TODO realloc funcs
void hcl_hash_free (struct hcl_hash *);

int hcl_hash_addent (struct hcl_hash *, char *, void *, enum hcl_type);
struct hcl_hash_ent *hcl_hash_getent (char *);

void hcl_hash_print (struct hcl_hash *);

static struct hcl_hash_ent *hcl_hash_ent_new (char *, void *, enum hcl_type);
static void hcl_hash_ent_free (struct hcl_hash_ent *);

#endif /* LIBHCL_HCL_HASH */
