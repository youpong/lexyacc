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

%union {
  char *word;
}

%token NOUN PRONOUN VERB ADVERB ADJECTIVE PREPOSITION CONJUNCTION ARTICLE
%token <word> AUXVERB NOUN_OR_VERB

%%
sentence_list: sentence '.' 
        | sentence '.' sentence_list 
        ;
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
        |  NOUN_OR_VERB { printf("subject(NOUN_OR_VERB): %s\n", $1); }
        |  PRONOUN
        |  ADJECTIVE subject
	|  ADVERB ADJECTIVE subject
        |  noun_phrase
        ;

noun_phrase: ARTICLE ADJECTIVE NOUN
        | ARTICLE NOUN
        | ARTICLE NOUN_OR_VERB {
	       printf("noun_phrase(NOUN_OR_VERB): %s\n", $2); }
        ;
	
verb:      NOUN_OR_VERB { printf("verb(NOUN_OR_VERB): %s\n", $1); }
        |  ADVERB VERB
        |  AUXVERB VERB
        |  verb NOUN_OR_VERB { printf("verb(NOUN_OR_VERB): %s\n", $2); }
        ;
       
object:	  NOUN
        | NOUN_OR_VERB { printf("object(NOUN_OR_VERB): %s\n", $1); }
        | ADJECTIVE object
	| ADVERB ADJECTIVE object
        ;
	
prep_phrase: PREPOSITION NOUN
        ;
%%
