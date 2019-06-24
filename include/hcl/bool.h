/**
 * @file bool.h
 * @brief HCL bool type
 * @author nukosuke
 */
#ifndef LIBHCL_HCL_BOOL_H
#define LIBHCL_HCL_BOOL_H
#include <stdbool.h>

/**
 * HCL bool type
 */
struct hcl_bool
{
  bool b;
};

struct hcl_bool *hcl_bool_new (bool);
void hcl_bool_free (struct hcl_bool *);

#endif /* LIBHCL_HCL_BOOL_H */
