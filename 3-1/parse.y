%{
#include <stdio.h>
#include "lex.yy.h"
#include "calc.h"
%}

%union {
       double dval;
       struct symtab *symp;
}

%token <symp> NAME FUNC
%token <dval> NUMBER

%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%type <dval> expression

%%
statement_list: statement '\n'
         | statement_list statement '\n'
	 ;
	 
statement: NAME '=' expression { $1->dval = $3; }
	 | expression          { printf("= %g\n", $1); }
	 ;

expression: expression '+' expression { $$ = $1 + $3; }
          | expression '-' expression { $$ = $1 - $3; }
	  | expression '*' expression { $$ = $1 * $3; }
	  | expression '/' expression {
	    	       if($3 == 0.0)
		       	     yyerror("divide by zero");
		       else
			     $$ = $1 / $3; }	  
	  | '-' expression %prec UMINUS { $$ = -$2; }
	  | '(' expression ')' { $$ = $2; }
	  | NUMBER             { $$ = $1; }
	  | NAME               { $$ = $1->dval; }
	  | NAME '(' expression ')' {
	          if($1->funcptr)
		          $$ = ($1->funcptr)($3);
		  else {
		          printf("%s not a function\n", $1->name);
		          $$ = 0.0;
		  }
              }
          | NAME '(' expression ',' expression ')' {
	          if($1->funcptr)
		          $$ = ($1->funcptr)($3,$5);
		  else {
		  	  printf("%s not a function\n", $1->name);
		          $$ = 0.0;
                  }
	      }
	  ;
%%
