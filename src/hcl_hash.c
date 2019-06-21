/**
 * @file hcl_hash.c
 * @brief Implementation of HCL hash table
 * @author nukosuke
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memset
#include <hcl/hash.h>

/**
 * Hash table allocator
 *
 * @param size default size of the table
 * @return Pointer of allocated table
 */
struct hcl_hash *hcl_hash_new (size_t size)
{
  struct hcl_hash *hash = (struct hcl_hash *) malloc (sizeof (struct hcl_hash));
  if (hash == NULL)
    return NULL;

  hash->ent = (struct hcl_hash_ent **) malloc (sizeof (struct hcl_hash_ent *) * size);
  if (hash->ent == NULL)
    {
      free (hash);
      return NULL;
    }

  // Zero fill to terminate iteration by NULL comparison
  memset (hash->ent, 0, sizeof (*hash->ent));
  hash->cursor = hash->ent;
  hash->size = size;

  return hash;
}

/**
 * Hash table destructor
 *
 * @param hash Pointer of the table to be deleted
 */
void hcl_hash_free (struct hcl_hash *hash)
{
  for (struct hcl_hash_ent **ent = hash->ent; *ent != NULL; ent++)
    hcl_hash_ent_free (*ent);

  free (hash->ent);
  free (hash);
}

/**
 * Add new entry to hash table
 *
 * @param hash Pointer of hash table
 * @param name The name of entry
 * @param addr Address of value data
 * @param type HCL type
 * @return Status of addition
 */
int hcl_hash_addent (struct hcl_hash *hash, char *name, void *addr, enum hcl_type type)
{
  *hash->cursor = hcl_hash_ent_new (name, addr, type);
  if (*hash->cursor == NULL)
    return 1;

  hash->cursor++;
  return 0;
}

struct hcl_hash_ent *hcl_hash_getent (char *name)
{
  // TODO: calc string hash and searh from list
  return 0;
}

/**
 * Print hash table entries to stdout
 *
 * @param hash Pointer of hash table
 */
void hcl_hash_print (struct hcl_hash *hash)
{
  for (struct hcl_hash_ent **ent = hash->ent; *ent != NULL; ent++)
    {
      printf ("type: %d\t", (*ent)->type);
      printf ("name: %s\t", (*ent)->name);
      printf ("addr: %p\n", (*ent)->addr);
    }
}

/**
 * Hash table entry allocator
 *
 * @param key Entry key
 * @param addr Address of value data
 * @param type HCL type
 * @return Pointer of allocated hash table entry
 */
static struct hcl_hash_ent *hcl_hash_ent_new (char *name, void *addr, enum hcl_type type)
{
  struct hcl_hash_ent *ent = (struct hcl_hash_ent *) malloc (sizeof (struct hcl_hash_ent));
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

/**
 * Hash table entry destructor
 *
 * @param ent Pointer of hash table entry
 */
static void hcl_hash_ent_free (struct hcl_hash_ent *ent)
{
  free (ent->name);
  free (ent);
}
