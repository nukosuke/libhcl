##################################################
# STDIN
##################################################

add_executable (hcl_stdin hcl_stdin.c)
target_include_directories (hcl_stdin
  PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries (hcl_stdin hcl)
