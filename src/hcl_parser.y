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
%token <ival> IDENT
%token <ival>
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
%token <sval> ANY_STRING

%start config_file

%%

config_file
  : body;

body
  : attribute
  | body attribute
  | block
  | body block
  | one_line_block
  | body one_line_block;

attribute : IDENT EQ expression NEW_LINE;

block
  : IDENT _string_lit_or_ident L_CURL NEW_LINE R_CURL NEW_LINE;
one_line_block
  : IDENT _string_lit_or_ident L_CURL _ident_expr_or_none R_CURL NEW_LINE;
string_lit
  : '"' ANY_STRING '"'
  | "\"\"";
_string_lit_or_ident
  : string_lit
  | _string_lit_or_ident string_lit
  | IDENT
  | _string_lit_or_ident IDENT;
_ident_expr_or_none
  : IDENT EQ expression
  |;

expression
  : expr_term
  | operation
  | conditional;

expr_term
  : literal_value;

literal_value
  : NUMERIC_LIT
  | "true"
  | "false"
  | "null";

operation
  : unary_op
  | binary_op;

unary_op
  : SUB expr_term
  | NOT expr_term;

binary_op
  : expr_term binary_operator expr_term;

binary_operator
  : compare_operator
  | arithmetic_operator
  | logic_operator;

compare_operator
  : DBL_EQ | NOT_EQ | LT | GT | LT_EQ | GT_EQ;

arithmetic_operator
  : ADD | SUB | MUL | DIV | REM;

logic_operator
  : AND | OR | NOT;

conditional
  : expression QUEST expression COLON expression;

%%

void yyerror (const char *err)
{
  fprintf(stderr, "[E] %s\n", err);
}

int yywrap (void)
{
  return 1;
}

int hcl_parse (FILE *fptr, struct hcl_t *hcl)
{
  //  extern int yyparse (void);
  extern FILE *yyin;

  yyin = fptr;
  if (yyparse())
    {
      return 1;
    }
  return 0;
}
