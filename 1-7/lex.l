%{
/*
 *
 */
%}

%option nounput noinput

%%
\/\/.* |
\/\*[^*]*\*\/ { printf("%s: is comment\n", yytext); }
.|\n		;
%%
