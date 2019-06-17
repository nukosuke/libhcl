%{
#include "hcl_parser.h"
%}

%%

%{ /* Keywords */ %}

+   { return (ADD)      }
-   { return (SUB)      }
*   { return (MUL)      }
/   { return (DIV)      }
%   { return (REM)      }

&&  { return (AND)      }
||  { return (OR)       }
!   { return (NOT)      }

==  { return (DBL_EQ)   }
!=  { return (NOT_EQ)   }

<   { return (LT)       }
>   { return (GT)       }
<=  { return (LT_EQ)    }
>=  { return (GT_EQ)    }

:   { return (COLON)    }
?   { return (QUEST)    }

{   { return (L_CURL)   }
}   { return (R_CURL)   }
=   { return (EQ)       }
=>  { return (ARROW)    }

[   { return (L_BRACK)  }
]   { return (R_BRACK)  }

(   { return (L_PAREN)  }
)   { return (R_PAREN)  }
.   { return (PERIOD)   }
,   { return (COMMA)    }
... { return (DOTS)     }

${  { return (DAL_CURL) }
%{  { return (PER_CURL) }

%%
