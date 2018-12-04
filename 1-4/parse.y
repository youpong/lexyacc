%{
/*
 * A lexor for the basic grammer to use for recognizing english sentence.
 */
#include <stdio.h>
#include <stdlib.h>
#include "lex.yy.h"
int yyerror(char *);
%}

%token NOUN PRONOUN VERB ADVERB ADJECTIVE PREPOSITION CONJUNCTION

%%
sentence: subject VERB object { printf("Sentence is valid.\n"); }
        ;

subject:  NOUN
       |  PRONOUN
       ;
object:	  NOUN
      ;
%%
extern FILE *yyin;

int
main(int argc, char* argv[])
{
	if(yyin == NULL) {
		yyin = stdin;
	}
	while(!feof(yyin)) {
		yyparse();
	}
	return EXIT_SUCCESS;
}

int
yyerror(char *s)
{
	fprintf(stderr, "%s\n", s);
	return 0;	
}