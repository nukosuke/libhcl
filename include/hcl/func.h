/**
 * @file func.h
 * @brief Functions for HCL function
 * @author nukosuke
 */
#ifndef LIBHCL_HCL_FUNC_H
#define LIBHCL_HCL_FUNC_H
#include <hcl/types.h>

struct hcl_func
{
  struct hcl_list *args; /* signature of arguments */
};

void hcl_def_func (char *name);

#endif /* LIBHCL_HCL_FUNC_H */
