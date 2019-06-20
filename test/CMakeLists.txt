enable_testing ()

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
