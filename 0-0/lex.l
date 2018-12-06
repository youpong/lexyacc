%{
#include "y.tab.h"
#include "main.h"
%}

%option nounput noinput

%%
[ \t]+ ; /* ignore white space */
end    { return 0; }
.+     { return WORD; }
%%
