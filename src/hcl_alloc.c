/**
 * @file hcl_alloc.c
 * @brief Implementation of memory allocation for HCL
 * @author nukosuke
 */
#include <stdlib.h>
#include <string.h>
#include "hcl_alloc.h"


struct hcl_string
{
  char *ptr;
};

struct hcl_number
{
  double val;
};

struct hcl_bool
{
  bool val;
};

struct hcl_tuple
{
  struct hcl_tuple_elem *elem;
};

struct hcl_tuple_elem
{
};

/**
 * Allocate HCL string
 *
 * @param val The string to be assigned
 * @return Status of allocation
 */
int hcl_string (char *val)
{
  struct hcl_string *s = (struct hcl_string *) malloc (sizeof (struct hcl_string));
  if (s == NULL)
    return 1;
  
  s->ptr = (char *) malloc (sizeof (val));
  if (s->ptr == NULL)
    return 1;

  strcpy (val, s->ptr);

  // TODO hcl_symtbl_addent (HCL_STRING_T, (void *) s)

  return 0;
}

/**
 * Allocate HCL number
 *
 * @param val The number to be assigned
 * @return Status of allocation
 */
int hcl_number (double val)
{
  struct hcl_number *n = (struct hcl_number *) malloc (sizeof (struct hcl_number));
  if (n == NULL)
    return 1;

  n->val = val;
  return 0;
}

/**
 * Allocate HCL bool
 *
 * @param val The boolean to be assigned
 * @return Status of allocation
 */
int hcl_bool (bool val)
{
  struct hcl_bool *b = (struct hcl_bool *) malloc (sizeof (struct hcl_bool));
  if (b == NULL)
    return 1;

  b->val = val;
  return 0;
}

/**
 * Allocate HCL set
 */
int hcl_set ()
{
  return 1;
}

/**
 * Allocate HCL map
 */
int hcl_map ()
{
  return 1;
}

/**
 * Allocate HCL object
 */
int hcl_object ()
{
  return 1;
}

/**
 * Allocate HCL tuple
 */
int hcl_tuple ()
{
  return 1;
}
