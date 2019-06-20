/**
 * @file hcl.h
 * @brief Main header for HCL2 parsing
 * @author nukosuke <nukosuke@lavabit.com>
 */
#ifndef LIBHCL_HCL_H
#define LIBHCL_HCL_H
#include <stdio.h>
#include <hcl/types.h>

struct hcl_t *hcl_new (void);
void hcl_free (struct hcl_t *hcl);
int hcl_init (struct hcl_t *hcl);
int hcl_parse (FILE *fp, struct hcl_t *hcl);
int hcl_parse_string (char *str, struct hcl_t *hcl);

#endif /* LIBHCL_HCL_H */
