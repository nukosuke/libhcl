/**
 * @file hcl.h
 * @brief Main header for HCL2 parsing
 * @author nukosuke <nukosuke@lavabit.com>
 */
#ifndef LIBHCL_HCL_H
#define LIBHCL_HCL_H
#include <stdio.h>
#include <hcl/types.h>

/**
 * @fn
 * @brief Constructor of HCL config
 * @return Pointer of HCL config object
 */
struct hcl_t *hcl_new (void);

/**
 * @fn
 * @brief Destructor of HCL config
 * @param hcl Pointer of HCL config object
 */
void hcl_free (struct hcl_t *hcl);

/**
 * @fn
 * @brief Initialize HCL config object
 * @param hcl Pointer of HCL config object
 * @return The init status
 */
int hcl_init (struct hcl_t *hcl);

/**
 * @fn
 * @brief Parse HCL file into HCL config object
 * @param fp File handler of HCL config file
 * @param hcl HCL config object to be written
 * @return The parse status
 */
int hcl_parse (FILE *fp, struct hcl_t *hcl);

/**
 * @fn
 * @brief Parse HCL string into HCL config object
 * @param str HCL string
 * @param hcl HCL config object to be written
 * @return The parse status
 */
int hcl_parse_string (char *str, struct hcl_t *hcl);

#endif /* LIBHCL_HCL_H */
