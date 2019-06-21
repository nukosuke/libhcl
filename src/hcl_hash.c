/**
 * @file hcl_object.c
 * @brief Implementation of HCL hash table
 * @author nukosuke
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memset
#include <hcl/object.h>

/**
 * Allocator of object type
 *
 * @param size default size of the table
 * @return Pointer of allocated table
 */
struct hcl_object *hcl_object_new (size_t size)
{
  struct hcl_object *object = (struct hcl_object *) malloc (sizeof (struct hcl_object));
  if (object == NULL)
    return NULL;

  object->ent = (struct hcl_object_ent **) malloc (sizeof (struct hcl_object_ent *) * size);
  if (object->ent == NULL)
    {
      free (object);
      return NULL;
    }

  // Zero fill to terminate iteration by NULL comparison
  memset (object->ent, 0, sizeof (*object->ent));
  object->cursor = object->ent;
  object->size = size;

  return object;
}

/**
 * Destructor of object type
 *
 * @param object Pointer of the table to be deleted
 */
void hcl_object_free (struct hcl_object *object)
{
  for (struct hcl_object_ent **ent = object->ent; *ent != NULL; ent++)
    hcl_object_ent_free (*ent);

  free (object->ent);
  free (object);
}

/**
 * Add new entry to object
 *
 * @param object Pointer of object
 * @param name The name of entry
 * @param addr Address of value data
 * @param type HCL type
 * @return Status of addition
 */
int hcl_object_addent (struct hcl_object *object, char *name, void *addr, enum hcl_type type)
{
  // TODO:
  //   BREAKING CHANGE
  //
  // This function should use objecting of the key string
  // and route it to head entry of list chain.

  *object->cursor = hcl_object_ent_new (name, addr, type);
  if (*object->cursor == NULL)
    return 1;

  object->cursor++;
  return 0;
}

struct hcl_object_ent *hcl_object_getent (char *name)
{
  // TODO: calc string object and searh from list
  return 0;
}

/**
 * Print object entries to stdout
 *
 * @param object Pointer of object
 */
void hcl_object_print (struct hcl_object *object)
{
  for (struct hcl_object_ent **ent = object->ent; *ent != NULL; ent++)
    {
      printf ("type: %d\t", (*ent)->type);
      printf ("name: %s\t", (*ent)->name);
      printf ("addr: %p\n", (*ent)->addr);
    }
}

/**
 * Allocator of object entry
 *
 * @param key Entry key
 * @param addr Address of value data
 * @param type HCL type
 * @return Pointer of allocated object entry
 */
static struct hcl_object_ent *hcl_object_ent_new (char *name, void *addr, enum hcl_type type)
{
  struct hcl_object_ent *ent = (struct hcl_object_ent *) malloc (sizeof (struct hcl_object_ent));
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
  ent->next = NULL;

  return ent;
}

/**
 * Hash table entry destructor
 *
 * @param ent Pointer of object entry
 */
static void hcl_object_ent_free (struct hcl_object_ent *ent)
{
  while (ent)
    {
      struct hcl_object_ent *prev = ent;
      ent = ent->next;
      free (prev->name);
      free (prev);
    }
}
