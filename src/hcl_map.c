/**
 * @file hcl_map.c
 * @brief Implementation of HCL map type
 * @author nukosuke
 */
#include <stdlib.h>
#include <hcl/map.h>

/**
 * Allocator of HCL map type
 *
 * @return Pointer of HCL map type
 */
struct hcl_map *hcl_map_new (void)
{
  struct hcl_map *map = (struct hcl_map *) malloc (sizeof (struct hcl_map));
  return map;
}

/**
 * Destructor of HCL map type
 *
 * @param map Pointer of HCL map type
 */
void hcl_map_free (struct hcl_map *map)
{
  free (map);
}
