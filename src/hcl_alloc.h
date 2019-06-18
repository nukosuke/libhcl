/**
 * @file hcl_alloc.h
 * @brief Memory allocation for HCL types
 * @author nukosuke
 */
#ifndef LIBHCL_HCL_ALLOC_H
#define LIBHCL_HCL_ALLOC_H

int hcl_string ();

int hcl_number ();

int hcl_bool ();

int hcl_list ();

int hcl_set ();

int hcl_map ();

int hcl_object ();

int hcl_tuple ();

#endif /* LIBHCL_HCL_ALLOC_H */
