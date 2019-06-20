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
