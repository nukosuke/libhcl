%{
#include <stdio.h>

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

config_file : ADD;
