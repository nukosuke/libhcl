##################################################
# Setup
##################################################

find_package (Check REQUIRED)
include_directories (${PROJECT_SOURCE_DIR}/include ${CHECK_INCLUDE_DIRS})
link_libraries (hcl ${CHECK_LIBRARIES} pthread)
link_directories (${CHECK_LIBRARY_DIRS})

##################################################
# STDIN
##################################################

add_executable (hcl_stdin hcl_stdin.c)

##################################################
# Symbol Table printer
##################################################

add_executable (hcl_symtbl hcl_symtbl.c)

##################################################
# Tests for HCL data type
##################################################

#
# list
#
add_executable (test_hcl_list test_hcl_list.c)
add_test (test_hcl_list ${CMAKE_CURRENT_BINARY_DIR}/test_hcl_list)

#
# map
#
add_executable (test_hcl_map test_hcl_map.c)
add_test (test_hcl_map ${CMAKE_CURRENT_BINARY_DIR}/test_hcl_map)
