/**
 * @file types.h
 * @brief Type definitions for LibHCL
 * @author nukosuke
 */
#ifndef LIBHCL_HCL_TYPES
#define LIBHCL_HCL_TYPES

enum hcl_type {
  // Only for variable table
  HCL_STRING_T,
  HCL_NUMBER_T,
  HCL_BOOL_T,
  HCL_LIST_T,
  HCL_MAP_T,
  HCL_OBJECT_T,
  HCL_TUPLE_T,

  // Only for function table
  HCL_FUNC_T,
};

/**
 * Symbol table for HCL function
 * This is global scope symbol table.
 */
struct hcl_t //func_table
{
  struct hcl_object *h; /*!< Hash table for function entries */
};

/**
 * Symbol table for HCL variable
 * This hash table might be nested for name scope(.)
 * and variable table is config local scope.
 */
struct hcl_var_table
{
  struct hcl_object *h; /*!< Hash table for variable entries */
};

#endif /* LIBHCL_HCL_TYPES */
