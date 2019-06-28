enable_testing ()

# TODO: package_find (Check REQUIRED)

##################################################
# STDIN
##################################################

add_executable (hcl_stdin hcl_stdin.c)
target_include_directories (hcl_stdin
  PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries (hcl_stdin hcl)

##################################################
# Symbol Table printer
##################################################

add_executable (hcl_symtbl hcl_symtbl.c)
target_include_directories (hcl_symtbl
  PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries (hcl_symtbl hcl)

##################################################
# Tests for HCL data type
##################################################

#
# list
#
add_executable (test_hcl_list test_hcl_list.c)
target_link_libraries(test_hcl_list hcl check)
add_test (test_hcl_list ${CMAKE_CURRENT_BINARY_DIR}/test_hcl_list)
