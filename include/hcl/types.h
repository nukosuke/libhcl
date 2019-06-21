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

/**
 * Symbol table for HCL function
 */
struct hcl_t //func_table
{
  struct hcl_object *h; /*!< Hash table for function entries */
};

/**
 * Symbol table for HCL variable
 * This hash table might be nested for name scope(.)
 */
struct hcl_var_table
{
  struct hcl_object *h; /*!< Hash table for variable entries */
};

#endif /* LIBHCL_HCL_TYPES */
