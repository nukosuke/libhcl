/**
 * @file hcl_list.c
 * @brief Implementation of HCL list type
 * @author nukosuke
 */
#include <stdlib.h>
#include <hcl/list.h>

/**
 * Allocate HCL list
 *
 * @return Pointer of allocated HCL list
 */
struct hcl_list *hcl_list_new (void)
{
  struct hcl_list *list = (struct hcl_list *) malloc (sizeof (struct hcl_list));
  if (list == NULL)
    return NULL;

  list->head = NULL;
  list->len  = 0;

  return list;
}

/**
 * Destruct HCL list
 *
 * @param list Pointer of HCL list
 */
void hcl_list_free (struct hcl_list *list)
{
  struct hcl_list_ent *ent = list->head;
  while (ent)
    {
      struct hcl_list_ent *prev = ent;
      ent = ent->next;
      free (prev);
    }
  free (list);
}

/**
 * Add entry to HCL list
 *
 * @param list Pointer of HCL list
 * @param addr Address of value data
 * @param type HCL type
 * @return Status of addition
 */
int hcl_list_addent (struct hcl_list *list, void *addr, enum hcl_type type)
{
  if ((list->tail->next = hcl_list_ent_new (addr, type)) == NULL)
    return 1;

  list->tail = list->tail->next;
  return 0;
}

/**
 * Allocator of HCL list entry
 *
 * @param addr Address of value data
 * @param type HCL type
 * @return Pointer of allocated HCL list entry
 */
static struct hcl_list_ent *hcl_list_ent_new (void *addr, enum hcl_type type)
{
  struct hcl_list_ent *ent = (struct hcl_list_ent *) malloc (sizeof (struct hcl_list_ent));
  if (ent == NULL)
    return NULL;

  ent->next = NULL;
  ent->addr = addr;
  ent->type = type;

  return ent;
}

/**
 * Destructor of HCL list entry
 *
 * @param ent Pointer of HCL list entry
 */
static void hcl_list_ent_free (struct hcl_list_ent *ent)
{
  free (ent->addr);
  free (ent);
}
