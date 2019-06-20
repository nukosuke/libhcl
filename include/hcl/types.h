/**
 * @file types.h
 * @brief Type definitions for LibHCL
 * @author nukosuke
 */
#ifndef LIBHCL_HCL_TYPES
#define LIBHCL_HCL_TYPES

enum hcl_type {
  HCL_STRING_T,
  HCL_NUMBER_T,
  HCL_BOOL_T,
  HCL_LIST_T,
  HCL_MAP_T,
  HCL_OBJECT_T,
  HCL_TUPLE_T,
};

struct hcl_t {
  // TODO symbol table
};

#endif /* LIBHCL_HCL_TYPES */
