/**
 * @file string.h
 * @brief HCL string type
 * @author nukosuke
 */
#ifndef LIBHCL_HCL_STRING_H
#define LIBHCL_HCL_STRING_H

/**
 * HCL string type
 */
struct hcl_string
{
  char *str;
};

struct hcl_string *hcl_string_new (char *);
void hcl_string_free (struct hcl_string *);

#endif /* LIBHCL_HCL_STRING_H */
