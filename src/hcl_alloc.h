/**
 * @file hcl_alloc.h
 * @brief Memory allocation for HCL types
 * @author nukosuke
 */
#ifndef LIBHCL_HCL_ALLOC_H
#define LIBHCL_HCL_ALLOC_H
#include <stdbool.h>

/**
 * @fn
 * @brief Allocate HCL string
 * @param val The string to be assigned
 */
int hcl_string (char *val);

/**
 * @fn
 * @brief Allocate HCL number
 * @param val The number to be assigned
 */
int hcl_number (double val);

/**
 * @fn
 * @brief Allocate HCL bool
 * @param val The boolean to be assigned
 */
int hcl_bool (bool val);

/**
 * @fn
 * @brief Allocate HCL list
 */
int hcl_list (void);

/**
 * @fn
 * @brief Allocate HCL set
 */
int hcl_set (void);

/**
 * @fn
 * @brief Allocate HCL map
 */
int hcl_map (void);

/**
 * @fn
 * @brief Allocate HCL object
 */
int hcl_object (void);

/**
 * @fn
 * @brief Allocate HCL tuple
 */
int hcl_tuple (void);

#endif /* LIBHCL_HCL_ALLOC_H */
