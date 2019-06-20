/**
 * @file list.h
 * @brief HCL list type
 * @author nukosuke
 */
#ifndef LIBHCL_HCL_LIST_H
#define LIBHCL_HCL_LIST_H
#include <stddef.h> // size_t

/**
 * HCL list type
 */
struct hcl_list
{
  struct hcl_list_ent *head;
  size_t len;
};

/**
 * Item of HCL list type
 */
struct hcl_list_ent
{
  struct hcl_list_ent *next;
  void *addr;
};

struct hcl_list *hcl_list_new (void);

#endif /* LIBHCL_HCL_LIST_H */
