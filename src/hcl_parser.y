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
%token <ival> TRUE_LIT
%token <ival> FALSE_LIT
%token <ival> NULL_LIT

%start config_file

%%

config_file : body;

body
  : attribute
  | body attribute
  | block
  | body block
  | one_line_block
  | body one_line_block;

attribute : IDENT EQ expression NEW_LINE;

block : IDENT;

one_line_block : IDENT NEW_LINE;

expression
  : expr_term
  | operation
  | conditional;

expr_term
  : literal_value;

literal_value
  : NUMERIC_LIT
  | TRUE_LIT
  | FALSE_LIT
  | NULL_LIT;

operation
  : unary_op
  | binary_op;

unary_op
  : SUB expr_term
  | NOT expr_term;

binary_op : expr_term binary_operator expr_term;

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
