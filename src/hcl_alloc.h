/**
 * @file hcl_alloc.h
 * @brief Memory allocation for HCL types
 * @author nukosuke
 */
#ifndef LIBHCL_HCL_ALLOC_H
#define LIBHCL_HCL_ALLOC_H

/**
 * @fn
 * @brief Allocate HCL string
 */
int hcl_string (void);

/**
 * @fn
 * @brief Allocate HCL number
 */
int hcl_number (void);

/**
 * @fn
 * @brief Allocate HCL bool
 */
int hcl_bool (void);

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
