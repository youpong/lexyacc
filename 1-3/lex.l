%{
/*
 * Word recognizer with a symbol table.
 */
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
WORD_TYPE state;
%}

%option nounput noinput

%%
\n	  { state = LOOKUP; /* end of line, return to default state */ }

^verb	  { state = VERB; }
^adj	  { state = ADJ; }
^adv	  { state = ADV; }
^noun	  { state = NOUN; }
^prep	  { state = PREP; }
^pron	  { state = PRON; }
^conj	  { state = CONJ; }

[a-zA-Z]+ { /* a normal word, define it or look it up */
	      if (state != LOOKUP) {
	          /* define the current word */
		  add_word(state, yytext);
	      } else {
	    	  switch(lookup_word(yytext)) {
		  case VERB: printf("%s: verb\n",        yytext);     break;
		  case ADJ:  printf("%s: adjective\n",   yytext);     break;
     		  case ADV:  printf("%s: adverb\n",      yytext);     break;
		  case NOUN: printf("%s: noun\n",        yytext);     break;
		  case PREP: printf("%s: preposition\n", yytext);     break;
		  case PRON: printf("%s: pronoun\n",     yytext);     break;
		  case CONJ: printf("%s: conjunction\n", yytext);     break;
		  default:   printf("%s: don't recognize\n", yytext); break;
	          }
              }
  	  }
.	  /* ignore anything else */	  
%%

int
main(int argc, char* argv[])
{
	yylex();

	return EXIT_SUCCESS;
}
