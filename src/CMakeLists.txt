add_library (hcl
  hcl.c
  hcl_func.c
  hcl_var.c
)

target_include_directories (hcl PUBLIC ${PROJECT_SOURCE_DIR}/include)
