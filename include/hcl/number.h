/**
 * @file number.h
 * @brief HCL number type
 * @author nukosuke
 */
#ifndef LIBHCL_HCL_NUMBER_H
#define LIBHCL_HCL_NUMBER_H

/**
 * HCL number type
 */
struct hcl_number
{
  // TODO
};

struct hcl_number *hcl_number_new (void);
void hcl_number_free (struct hcl_number *);

#endif /* LIBHCL_HCL_NUMBER_H */
