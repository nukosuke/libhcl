##################################################
# Lexer & Parser
##################################################

bison_target (hcl_parser
  hcl_parser.y
  ${CMAKE_CURRENT_BINARY_DIR}/hcl_parser.c
)

flex_target (hcl_lexer
  hcl_lexer.l
  ${CMAKE_CURRENT_BINARY_DIR}/hcl_lexer.c
)

add_flex_bison_dependency (hcl_lexer hcl_parser)

##################################################
# Build target
##################################################

add_library (hcl
  hcl.c
  hcl_alloc.c
  hcl_func.c
  hcl_symtbl.c
  hcl_var.c
  ${BISON_hcl_parser_OUTPUTS}
  ${FLEX_hcl_lexer_OUTPUTS}
)

##################################################
# Include directories
##################################################

include_directories (${CMAKE_CURRENT_BINARY_DIR})

target_include_directories (hcl
  PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)
