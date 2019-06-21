/**
 * @file list.h
 * @brief HCL list type
 * @author nukosuke
 */
#ifndef LIBHCL_HCL_LIST_H
#define LIBHCL_HCL_LIST_H
#include <stddef.h> // size_t
#include <hcl/types.h>

/**
 * HCL list type
 */
struct hcl_list
{
  struct hcl_list_ent *head;
  struct hcl_list_ent *tail;
  size_t len;
};

/**
 * Item of HCL list type
 */
struct hcl_list_ent
{
  struct hcl_list_ent *next;
  enum hcl_type type;
  void *addr;
};

struct hcl_list *hcl_list_new (void);
void hcl_list_free (struct hcl_list *);

int hcl_list_addent (struct hcl_list *, void *, enum hcl_type);

static struct hcl_list_ent *hcl_list_ent_new (void *addr, enum hcl_type type);
static void hcl_list_ent_free (struct hcl_list_ent *);

#endif /* LIBHCL_HCL_LIST_H */
