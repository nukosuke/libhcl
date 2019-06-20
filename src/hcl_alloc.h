/**
 * @file hcl_alloc.h
 * @brief Memory allocation for HCL types
 * @author nukosuke
 */
#ifndef LIBHCL_HCL_ALLOC_H
#define LIBHCL_HCL_ALLOC_H
#include <stdbool.h>

int hcl_string (char *val);
int hcl_number (double val);
int hcl_bool (bool val);
int hcl_list (void);
int hcl_set (void);
int hcl_map (void);
int hcl_object (void);
int hcl_tuple (void);

#endif /* LIBHCL_HCL_ALLOC_H */
