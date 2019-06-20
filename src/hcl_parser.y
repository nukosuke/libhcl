%{
/**
 * HCL Parser
 *
 * @file hcl_parser.c
 * @author nukosuke
 */
#include <stdio.h>
#include <hcl/types.h>

int yylex ();
void yyerror (const char *err);
%}

%union {
  int    ival;
  double dval;
  char   cval;
  char   *sval;
}

%token NEW_LINE
%token ADD SUB MUL DIV REM
%token AND OR NOT
%token DBL_EQ NOT_EQ
%token LT GT LT_EQ GT_EQ
%token COLON QUEST
%token L_CURL R_CURL EQ ARROW
%token L_BRACK R_BRACK
%token L_PAREN R_PAREN PERIOD COMMA DOTS
%token DAL_CURL PER_CURL
%token <sval> IDENT
%token TRUE FALSE
%token NULL_LIT
%token <dval> NUMERIC_LIT
%token STRING_LIT
%token IF
%token FOR IN

%start config_file

%%

/**
 * ConfigFile
 */
config_file :
  body
    {
      printf("body => config_file\n");
    }
  ; /* config_file */

/**
 * Body
 */
body :
  attribute
    {
      printf("attribute => body\n");
    } |
  body attribute
    {
      printf("body attribute => body\n");
    } |
  block
    {
      printf("block => body\n");
    } |
  body block
    {
      printf("body block => body\n");
    } |
  one_line_block
    {
      printf("one_line_block => body\n");
    } |
  body one_line_block
    {
      printf("body one_line_block => body\n");
    }
  ; /* body */

/**
 * Attribute
 */
attribute :
  IDENT EQ expression NEW_LINE
    {
      printf("IDENT EQ expression NEW_LINE => attribute\n");
    }
  ; /* attribute */

/**
 * Block
 */
block :
  IDENT _string_lit_or_ident L_CURL NEW_LINE body R_CURL NEW_LINE
    {
      printf("IDENT _string_lit_or_ident L_CURL NEW_LINE body R_CURL NEW_LINE => block\n");
    }
  ; /* block */

one_line_block :
  IDENT _string_lit_or_ident L_CURL _ident_expr_or_empty R_CURL NEW_LINE
    {
      printf("IDENT _string_lit_or_ident L_CURL _ident_expr_or_empty R_CURL NEW_LINE => one_line_block\n");
    }
  ; /* one_line_block */

_string_lit_or_ident :
  STRING_LIT
    {
      printf("STRING_LIT => _string_lit_or_ident\n");
    } |
  _string_lit_or_ident STRING_LIT
    {
      printf("_string_lit_or_ident STRING_LIT => _string_lit_or_ident\n");
    } |
  IDENT
    {
      printf("IDENT => _string_lit_or_ident\n");
    } |
  _string_lit_or_ident IDENT
    {
      printf("_string_lit_or_ident IDENT => _string_lit_or_ident\n");
    }
  ; /* _string_lit_or_ident */

_ident_expr_or_empty :
  IDENT EQ expression
    {
      printf("IDENT EQ expression => _ident_expr_or_empty\n");
    } |
  /* empty */
    {
      printf("/* empty */ => _ident_expr_or_empty\n");
    }
  ; /* _ident_expr_or_empty */

/**
 * Expression
 */
expression :
  expr_term
    {
      printf("expr_term => expression\n");
    } |
  operation
    {
      printf("operation => expression\n");
    } |
  conditional
    {
      printf("conditional => expression");
    }
  ; /* expression */

/**
 * ExprTerm
 */
expr_term :
  literal_value
    {
      printf ("literal_value => expr_term\n");
    } |
  collection_value
    {
      printf ("collection_value => expr_term\n");
    } |
  template_expr
    {
      printf ("template_expr => expr_term\n");
    } |
  variable_expr
    {
      printf ("variable_expr => expr_term\n");
    } |
  function_call
    {
      printf ("function_call => expr_term\n");
    } |
  for_expr
    {
      printf ("for_expr => expr_term\n");
    } |
  expr_term index
    {
      printf ("expr_term index => expr_term\n");
    } |
  expr_term get_attr
    {
      printf ("expr_term get_attr => expr_term\n");
    } |
  expr_term splat
    {
      printf ("expr_term splat => expr_term\n");
    } |
  L_PAREN expression R_PAREN
    {
      printf ("L_PAREN expression R_PAREN => expr_term\n");
    }
  ; /* expr_term */

/**
 * LiteralValue
 */
literal_value :
  NUMERIC_LIT
    {
      printf("NUMERIC_LIT => literal_value\n");
    } |
  TRUE
    {
      printf("TRUE => literal_value\n");
    } |
  FALSE
    {
      printf("FALSE => literal_value\n");
    } |
  NULL_LIT
    {
      printf("NULL_LIT => literal_value\n");
    }
  ; /* literal_value */

/**
 * CollectionValue
 */
collection_value :
  tuple |
  object
  ; /* collection_value */

tuple :
  L_BRACK _tuple_item R_BRACK
  ; /* tuple */

_tuple_item :
  expression |
  _tuple_item COMMA expression |
  _tuple_item COMMA
  ; /* _tuple_item */

object :
  L_CURL _object_item R_CURL
  ; /* object */

objectelem :
  IDENT EQ expression |
  expression EQ expression
  ; /* objectelem */

_object_item :
  objectelem |
  _object_item COMMA objectelem |
  _object_item COMMA
  ; /* _object_item */

/**
 * TemplateExpr
 */
template_expr :
  quoted_template |
  heredoc_template
  ; /* template_expr */

quoted_template :
  "TODO::quoted_template"
  ; /* quoted_template */

heredoc_template :
  "TODO::heredoc_template"
  ; /* heredoc_template */

/**
 * VariableExpr
 */
variable_expr :
  IDENT
    {
      printf ("IDENT => variable_expr\n");
    }
  ; /* variable_expr */

/**
 * FunctionCall
 */
function_call :
  IDENT L_PAREN arguments R_PAREN
  ; /* function_call */

arguments :
  expression
    {
      printf ("expression => arguments\n");
    } |
  arguments COMMA expression
    {
      printf ("arguments COMMA expression => arguments\n");
    } |
  arguments COMMA
    {
      printf ("arguments COMMA => arguments\n");
    } |
  arguments DOTS
    {
      printf ("arguments DOTS => arguments\n");
    } |
  /* empty */
    {
      printf ("/* empty */ => arguments\n");
    }
  ; /* arguments */

/**
 * ForExpr
 */
for_expr :
  for_tuple_expr |
  for_object_expr
  ; /* for_expr */

for_tuple_expr :
  L_BRACK for_intro expression R_BRACK |
  L_BRACK for_intro expression for_cond R_BRACK
  ; /* for_tuple_expr */

for_object_expr :
  L_CURL for_intro expression ARROW expression _optional_dots _optional_for_cond R_CURL
  ; /* for_object_expr */
_optional_dots :
  DOTS |
  /* empty */
  ; /* _optional_dots */
_optional_for_cond :
  for_cond |
  /* empty */
  ; /* _optional_for_cond */

for_intro :
  FOR IDENT _optional_second_ident IN expression COLON
  ; /* for_intro */
_optional_second_ident :
  COMMA IDENT |
  /* empty */
  ; /* _optional_second_ident */

for_cond :
  IF expression
  ; /* for_cond */

/**
 * Index
 */
index :
  L_BRACK expression R_BRACK
    {
      printf ("L_BRACK expression R_BRACK => index\n");
    }
  ; /* index */

/**
 * GetAttr
 */
get_attr :
  PERIOD IDENT
    {
      printf ("PERIOD IDENT => get_attr\n");
    }
  ; /* get_attr */

/**
 * Splat
 */
splat :
  attr_splat |
  full_splat
  ; /* splat */

attr_splat :
  PERIOD MUL |
  attr_splat get_attr
  ; /* attr_splat */

full_splat :
  L_BRACK MUL R_BRACK |
  full_splat get_attr |
  full_splat index
  ; /* full_splat */

/**
 * Operation
 */
operation :
  unary_op |
  binary_op
  ; /* operation */

unary_op :
  SUB expr_term |
  NOT expr_term
  ; /* unary_op */

binary_op :
  expr_term binary_operator expr_term
    {
      printf("binary_op\n");
    }
  ; /* binary_op */

binary_operator :
  compare_operator
    {
      printf("compare_operator\n");
    } |
  arithmetic_operator
    {
      printf("arithmetic_operator\n");
    } |
  logic_operator
    {
      printf("logic_operator\n");
    }
  ; /* binary_operator */

compare_operator :
  DBL_EQ | NOT_EQ | LT | GT | LT_EQ | GT_EQ
  ; /* compare_operator */

arithmetic_operator :
  ADD | SUB | MUL | DIV | REM
  ; /* arithmetic_operator */

logic_operator :
  AND | OR | NOT
  ; /* logic_operator */

/**
 * Conditional
 */
conditional :
  expression QUEST expression COLON expression
  ; /* conditional */

%%

void yyerror (const char *err)
{
  fprintf (stderr, "[E] %s\n", err);
}

int yywrap (void)
{
  return 1;
}

/**
 * Parse HCL file into HCL config object
 *
 * @param fp File handler of HCL config file
 * @param hcl HCL config object to be written
 * @return The parse status
 */
int hcl_parse (FILE *fp, struct hcl_t *hcl)
{
  extern FILE *yyin;

  yyin = fp;
  if (yyparse ())
    {
      return 1;
    }
  return 0;
}

/**
 * Parse HCL string into HCL config object
 *
 * @param str HCL string
 * @param hcl HCL config object to be written
 * @return The parse status
 */
int hcl_parse_string (char *str, struct hcl_t *hcl)
{
  return 1;
}
