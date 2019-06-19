%{
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
%token <sval> IDENT
%token
  ADD SUB MUL DIV REM
  AND OR NOT
  DBL_EQ NOT_EQ
  LT GT LT_EQ GT_EQ
  COLON QUEST
  L_CURL R_CURL EQ ARROW
  L_BRACK R_BRACK
  L_PAREN R_PAREN PERIOD COMMA DOTS
  DAL_CURL PER_CURL
%token TRUE FALSE
%token NULL_LIT
%token <dval> NUMERIC_LIT
%token STRING_LIT

%start config_file

%%

/**
 * ConfigFile
 */
config_file
  : body
  {
    printf("body => config_file\n");
  }
  ;

/**
 * Body
 */
body
  : attribute
  {
    printf("attribute => body\n");
  }
  | body attribute
  {
    printf("body attribute => body\n");
  }
  | block
  {
    printf("block => body\n");
  }
  | body block
  {
    printf("body block => body\n");
  }
  | one_line_block
  {
    printf("one_line_block => body\n");
  }
  | body one_line_block
  {
    printf("body one_line_block => body\n");
  }
  ;

/**
 * Attribute
 */
attribute
  : IDENT EQ expression NEW_LINE
  {
    printf("IDENT EQ expression NEW_LINE => attribute\n");
  }
  ;

/**
 * Block
 */
block
  : IDENT _string_lit_or_ident L_CURL NEW_LINE body R_CURL NEW_LINE
  {
    printf("IDENT _string_lit_or_ident L_CURL NEW_LINE body R_CURL NEW_LINE => block\n");
  }
one_line_block
  : IDENT _string_lit_or_ident L_CURL _ident_expr_or_none R_CURL NEW_LINE
  {
    printf("IDENT _string_lit_or_ident L_CURL _ident_expr_or_none R_CURL NEW_LINE => one_line_block\n");
  }
  ;
_string_lit_or_ident
  : STRING_LIT
  {
    printf("STRING_LIT => _string_lit_or_ident\n");
  }
  | _string_lit_or_ident STRING_LIT
  {
    printf("_string_lit_or_ident STRING_LIT => _string_lit_or_ident\n");
  }
  | IDENT
  {
    printf("IDENT => _string_lit_or_ident\n");
  }
  | _string_lit_or_ident IDENT
  {
    printf("_string_lit_or_ident IDENT => _string_lit_or_ident\n");
  }
  ;
_ident_expr_or_none
  : IDENT EQ expression
  {
    printf("IDENT EQ expression => _ident_expr_or_none\n");
  }
  | /* none */
  {
    printf("/* none */ => _ident_expr_or_none\n");
  }
  ;

/**
 * Expression
 */
expression
  : expr_term
  {
    printf("expr_term => expression\n");
  }
  | operation
  {
    printf("operation => expression\n");
  }
  | conditional
  {
    printf("conditional => expression");
  }
  ;

/**
 * ExprTerm
 */
expr_term
  : literal_value
  {
    printf("literal_value => expr_term\n");
  }
  | collection_value
  {
    printf("collection_value => expr_term\n");
  }
  | template_expr
  {
    printf("template_expr => expr_term\n");
  }
  | variable_expr
  {
    printf ("variable_expr => expr_term\n");
  }
  | function_call
  {
    printf ("function_call => expr_term\n");
  }
  ;

/**
 * LiteralValue
 */
literal_value
  : NUMERIC_LIT
  {
    printf("NUMERIC_LIT => literal_value\n");
  }
  | TRUE
  {
    printf("TRUE => literal_value\n");
  }
  | FALSE
  {
    printf("FALSE => literal_value\n");
  }
  | NULL_LIT
  {
    printf("NULL_LIT => literal_value\n");
  }
  ;

/**
 * CollectionValue
 */
collection_value
  : tuple
  | object
  ;
tuple
  : L_BRACK _tuple_item R_BRACK
  ;
_tuple_item
  : expression
  | _tuple_item COMMA expression
  | _tuple_item COMMA
  ;
object
  : L_CURL _object_item R_CURL
  ;
objectelem
  : IDENT EQ expression
  | expression EQ expression
  ;
_object_item
  : objectelem
  | _object_item COMMA objectelem
  | _object_item COMMA
  ;

/**
 * TemplateExpr
 */
template_expr
  : quoted_template
  | heredoc_template
  ;
quoted_template : "TODO::quoted_template";
heredoc_template : "TODO::heredoc_template";

/**
 * VariableExpr
 */
variable_expr
  : IDENT
  {
    printf ("IDENT => variable_expr\n");
  }
  ;

/**
 * FunctionCall
 */
function_call
  : IDENT L_PAREN arguments R_PAREN
  ;
arguments
  : expression
  {
    printf ("expression => arguments\n");
  }
  | arguments COMMA expression
  {
    printf ("arguments COMMA expression => arguments\n");
  }
  | arguments COMMA
  {
    printf ("arguments COMMA => arguments\n");
  }
  | arguments DOTS
  {
    printf ("arguments DOTS => arguments\n");
  }
  | /* empty */
  {
    printf ("/* empty */ => arguments\n");
  }
  ;

/**
 * Operation
 */
operation
  : unary_op
  | binary_op
  ;
unary_op
  : SUB expr_term
  | NOT expr_term
  ;
binary_op
  : expr_term binary_operator expr_term
  {
    printf("binary_op\n");
  }
  ;
binary_operator
  : compare_operator
  {
    printf("compare_operator\n");
  }
  | arithmetic_operator
  {
    printf("arithmetic_operator\n");
  }
  | logic_operator
  {
    printf("logic_operator\n");
  }
  ;
compare_operator
  : DBL_EQ | NOT_EQ | LT | GT | LT_EQ | GT_EQ
  ;
arithmetic_operator
  : ADD | SUB | MUL | DIV | REM
  ;
logic_operator
  : AND | OR | NOT
  ;

/**
 * Conditional
 */
conditional
  : expression QUEST expression COLON expression
  ;

%%

void yyerror (const char *err)
{
  fprintf(stderr, "[E] %s\n", err);
}

int yywrap (void)
{
  return 1;
}

int hcl_parse (FILE *fp, struct hcl_t *hcl)
{
  extern FILE *yyin;

  yyin = fp;
  if (yyparse())
    {
      return 1;
    }
  return 0;
}
