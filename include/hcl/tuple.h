/**
 * @file tuple.h
 * @brief HCL tuple type
 * @author nukosuke
 */
#ifndef LIBHCL_HCL_TUPLE_H
#define LIBHCL_HCL_TUPLE_H

/**
 * HCL tuple type
 */
struct hcl_tuple
{
  // TODO
};

struct hcl_tuple *hcl_tuple_new (void);
void hcl_tuple_free (struct hcl_tuple *);

#endif /* LIBHCL_HCL_TUPLE_H */
