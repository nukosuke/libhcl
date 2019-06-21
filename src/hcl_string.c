/**
 * @file hcl_string.c
 * @brief Implementation of HCL string type
 * @author nukosuke
 */
#include <stdlib.h>
#include <string.h>
#include <hcl/string.h>

/**
 * Allocator of HCL string
 *
 * @param wc Wide character string
 * @return Pointer of HCL string
 */
struct hcl_string *hcl_string_new (char *u8str)
{
  struct hcl_string *str = (struct hcl_string *) malloc (sizeof (struct hcl_string));
  if (str == NULL)
    return NULL;

  str->str = (char *) malloc (sizeof (u8str));
  if (str->str == NULL)
    {
      free (str);
      return NULL;
    }

  strcpy(str->str, u8str);
  return str;
}

/**
 * Destructor of HCL string
 *
 * @param str Pointer of HCL string
 */
void hcl_string_free (struct hcl_string *str)
{
  free (str->str);
  free (str);
}
