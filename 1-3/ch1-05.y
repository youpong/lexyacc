%{
/*
 * A lexor for the basic grammer to use for recognizing english sentence.
 */
#include <stdio.h>
#include <stdlib.h>
#include "lex.yy.h"
#include "main.h"
%}

%union {
  char *word;
}

%token <word> NOUN PRONOUN VERB ADVERB ADJECTIVE PREPOSITION CONJUNCTION
%type <word> subject object

%%
sentence: subject VERB object {
              printf("Sentence is valid(s: %s, v: %s, o: %s).\n",
	          $1, $2, $3);
	  }
        ;

subject:  NOUN
       |  PRONOUN
       ;
object:	  NOUN
      ;
%%
