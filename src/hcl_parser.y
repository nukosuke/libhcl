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
  ADD
  SUB
  MUL
  DIV
  REM

%start config_file

%%

config_file : ADD;
