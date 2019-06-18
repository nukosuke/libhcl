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

%start config_file

%%

config_file : body;

body : ADD;

%%

void yyerror (const char *err)
{
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
