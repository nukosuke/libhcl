%{
#include "hcl_parser.h"
%}

white [ \t]

%%

{white}+ { return(HOGE) }

%%
