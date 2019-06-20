%{
#include "hcl_parser.h"
%}

id_start    [a-zA-Z]
id_continue [a-zA-Z0-9_-]

decimal     [0-9]
expmark     [eE][+-]?

prose [a-zA-Z\n\r\t\"\\]
%%

%{
/**
 * Keywords
 * Operators and Delimiters
 */
%}

"+"   { return (ADD);      }
"-"   { return (SUB);      }
"*"   { return (MUL);      }
"/"   { return (DIV);      }
"%"   { return (REM);      }

"&&"  { return (AND);      }
"||"  { return (OR);       }
"!"   { return (NOT);      }

"=="  { return (DBL_EQ);   }
"!="  { return (NOT_EQ);   }

"<"   { return (LT);       }
">"   { return (GT);       }
"<="  { return (LT_EQ);    }
">="  { return (GT_EQ);    }

":"   { return (COLON);    }
"?"   { return (QUEST);    }

"{"   { printf("L_CURL\n"); return (L_CURL);   }
"}"   { printf("R_CURL\n"); return (R_CURL);   }
"="   { printf("EQ\n"); return (EQ);       }
"=>"  { return (ARROW);    }

"["   { return (L_BRACK);  }
"]"   { return (R_BRACK);  }

"("   { return (L_PAREN);  }
")"   { return (R_PAREN);  }
"."   { return (PERIOD);   }
","   { return (COMMA);    }
"..." { return (DOTS);     }

"${"  { return (DAL_CURL); }
"%{"  { return (PER_CURL); }

"true"  { return (TRUE);     }
"false" { return (FALSE);    }
"null"  { return (NULL_LIT); }

"if"  { return (IF);  }
"for" { return (FOR); }
"in"  { return (IN);  }

[\n\r] { return (NEW_LINE); }

%{
/* suppress whitespace output */
%}
" "+

%{
/**
 * Identifier
 */
%}

{id_start}{id_continue}*  {
  yylval.sval = yytext;
  printf("IDENT: %s\n", yylval.sval);
  return (IDENT);
}

%{
/**
 * Numeric Literals
 */
%}

{decimal}+("."{decimal}+)?({expmark}{decimal}+)?    {
  yylval.dval = atof (yytext);
  printf("NUMERIC_LIT: %f\n", yylval.dval);
  return (NUMERIC_LIT);
}

%{
/**
 * String Literals
 * TODO: punctual Unicode range
 */
%}

"\""[a-zA-Z0-9_\\\- ]*"\""  {
  yylval.sval = yytext;
  printf("STRING_LIT: %s\n", yylval.sval);
  return (STRING_LIT);
}

%%
