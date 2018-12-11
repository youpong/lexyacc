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
^#.*$   ; /* ignore */
\n	{ state = LOOKUP; }
\.      { state = LOOKUP; return '.'; }
verb 	{ state = VERB;   printf("VERB\n");}
adj  	{ state = ADJECTIVE; }
adv	{ state = ADVERB; printf("ADVERB\n");}
aux     { state = AUXVERB; printf("AUXVERB\n"); }
noun 	{ state = NOUN; }
prep	{ state = PREPOSITION; }
pron	{ state = PRONOUN; }
conj	{ state = CONJUNCTION; }
article { state = ARTICLE; }
norv    { state = NOUN_OR_VERB; }

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
        case AUXVERB:     return AUXVERB;
	case NOUN:        return NOUN;
	case PREPOSITION: return PREPOSITION;
	case PRONOUN:     return PRONOUN;
        case CONJUNCTION: return CONJUNCTION;
        case ARTICLE:     return ARTICLE;
        case NOUN_OR_VERB:return NOUN_OR_VERB;
	default: /* don't return, just ignore it */
	    printf("%s: don't recognize\n", yytext);
	}
    }
}

.	  ; /* ignore */
%%
