%{
/*
 * We found the following required for some yacc implementations. 
 * #define YYSTYPE int
 *
 * A lexor for the basic grammer to use for recognizing english sentence.
 */
#include <stdio.h>
#include <stdlib.h>
#include "lex.yy.h"
#include "main.h"
%}

%token NOUN PRONOUN VERB ADVERB ADJECTIVE PREPOSITION CONJUNCTION ARTICLE

%%
sentence: simple_sentence   { printf("Parsed a simple sentence.\n"); }
        | compound_sentence { printf("Parsed a compound sentence.\n"); }
	;
	
simple_sentence: subject verb object
        |        subject verb object prep_phrase
        ;

compound_sentence: simple_sentence CONJUNCTION simple_sentence
        | compound_sentence CONJUNCTION simple_sentence
	;
	
subject:   NOUN
        |  PRONOUN
        |  ADJECTIVE subject
	|  ADVERB ADJECTIVE subject
        |  noun_phrase
        ;

noun_phrase: ARTICLE ADJECTIVE NOUN
        | ARTICLE NOUN
        ;
	
verb:     VERB
        |  ADVERB VERB
        |  verb VERB
        ;
       
object:	  NOUN
        |  ADJECTIVE object
	| ADVERB ADJECTIVE object
        ;
	
prep_phrase: PREPOSITION NOUN
        ;
%%
