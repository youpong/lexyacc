%{
/*
 * A lexor for the basic grammer to use for recognizing english sentence.
 */
#include <stdio.h>
#include <stdlib.h>
#include "lex.yy.h"
#include "main.h"
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
