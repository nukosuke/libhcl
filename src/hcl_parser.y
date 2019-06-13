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

%token <ival> HOGE

%start config_file

%%

config_file : HOGE;
