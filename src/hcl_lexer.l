%{
#include "hcl_parser.h"
%}

%%

/* Keywords */
+   { return (ADD)  }
-   { return (SUB) }
*   { return (MUL)   }
/   { return (DIV)   }
%   { return (REM)   }

&&  { return (AND)   }
||  { return (OR)    }
!   { return (NOT)   }

==  { return (DOUBLE_EQ) }
!=  { return (NEQ)   }

<   { return (LT)    }
>   { return (GT)    }
<=  { return (LEQ)   }
>=  { return (GEQ)   }

:   { return (COLON) }
?   { return (QUEST) }

{   { return (L_CURL) }
}   { return (R_CURL) }
=   { return (EQUAL)  }
=>  { return (FAT_ARROW) }

[ { return (L_BRACKET) }
] { return (R_BRACKET) }

( { return (L_PAREN) }
) { return (R_PAREN) }
. { return (DOT) }
, { return (COMMA) }
... { return (DOTS) }

${ { return (OPEN_EVAL) }
%{ { return (OPEN_EVAL2) }

%%
