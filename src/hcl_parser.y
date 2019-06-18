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
%token <dval> NUMERIC_LIT
%token STRING_LIT

%start config_file

%%

config_file
  : body
  {
    printf("body\n");
  }
  ;

body
  : attribute
  {
    printf("attribute\n");
  }
  | body attribute
  {
    printf("body attribute\n");
  }
  | block
  {
    printf("block\n");
  }
  | body block
  {
    printf("body block");
  }
  ;

attribute
  : IDENT EQ expression NEW_LINE
  {
    printf("attr\n");
  }
  ;

block
  : IDENT _string_lit_or_ident L_CURL NEW_LINE R_CURL NEW_LINE
  {
    printf("block\n");
  }
  | IDENT _string_lit_or_ident L_CURL _ident_expr_or_none R_CURL NEW_LINE
  {
    printf("one_line_block\n");
  }
  ;
string_lit
  : STRING_LIT
  {
    printf("string_lit\n");
  }
  ;
_string_lit_or_ident
  : string_lit
  {
    printf("+sting_lit\n");
  }
  | _string_lit_or_ident string_lit
  {
    printf("_string_lit\n");
  }
  | IDENT
  {
    printf("_ident\n");
  }
  | _string_lit_or_ident IDENT
  {
    printf("_string ident\n");
  }
  ;
_ident_expr_or_none
  : IDENT EQ expression
  {
    printf("ident = expression\n");
  }
  | /* none */
  {
    printf("none\n");
  }
  ;

expression
  : expr_term
  {
    printf("expr_term\n");
  }
  | operation
  {
    printf("operation\n");
  }
  | conditional
  {
    printf("conditional");
  }
  ;

expr_term
  : literal_value
  {
    printf("literal_value\n");
  }
  ;

literal_value
  : NUMERIC_LIT
  {
    printf("numeric_lit\n");
  }
  | "true"
  | "false"
  | "null"
  ;

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
