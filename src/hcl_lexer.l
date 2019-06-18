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
 * Identifier
 */
%}

^{id_start}{id_continue}* { return (IDENT); }


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

"{"   { return (L_CURL);   }
"}"   { return (R_CURL);   }
"="   { return (EQ);       }
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

{prose}+ {
  return (ANY_STRING);
}

%{
/**
 * Numeric Literals
 */
%}

{decimal}+("."{decimal}+)?({expmark}{decimal}+)?    {
  yylval.dval = atof (yytext);
  return (NUMERIC_LIT);
}

%%
