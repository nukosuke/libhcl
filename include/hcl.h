/**
 * @file hcl.h
 * @brief Main header for HCL2 parsing
 * @author nukosuke <nukosuke@lavabit.com>
 */
#ifndef LIBHCL_HCL_H
#define LIBHCL_HCL_H
#include <hcl/types.h>

/**
 * @fn
 * @brief Constructor of HCL parser
 * @return Pointer of HCL parser object
 */
hcl_parser* hcl_new (void);

/**
 * @fn
 * @brief Destructor of HCL parser
 * @param hcl Pointer of HCL parser object
 */
void hcl_free (hcl_parser* hcl);

#endif /* LIBHCL_HCL_H */
