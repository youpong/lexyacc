%{
/*
 * We now build a lexical analyzer to be used by a higher-level parser.
 */

#include "main.h" 
#include "y.tab.h" /* token codes from the parser */
#include <string.h>
static int state;
%}

%option nounput noinput

%%
^#.*$   ; /* ignore comment */
\n	{ state = LOOKUP; }
\.\n	{ state = LOOKUP;
	  return 0; /* end of sentence */
	}
	
verb 	{ state = VERB; }
adj  	{ state = ADJECTIVE; }
adv	{ state = ADVERB; }
noun 	{ state = NOUN; }
prep	{ state = PREPOSITION; }
pron	{ state = PRONOUN; }
conj	{ state = CONJUNCTION; }

[a-zA-Z]+ {
    if(state != LOOKUP) {
        if(!add_word(state, yytext)) {
    	    printf("!!! warning: word %s already defined\n", yytext);
	}    
    } else {
        yylval.word = strdup(yytext);
	switch(lookup_word(yytext)) {
	case VERB:        return VERB;
	case ADJECTIVE:   return ADJECTIVE;
	case ADVERB:      return ADVERB;
	case NOUN:        return NOUN;
	case PREPOSITION: return PREPOSITION;
	case PRONOUN:     return PRONOUN;
	case CONJUNCTION: return CONJUNCTION;
	default: /* don't return, just ignore it */
	    printf("%s: don't recognize\n", yytext);
	}
    }
}    
.	  ; /* ignore */
%%
