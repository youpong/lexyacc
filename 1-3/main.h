typedef enum {
     LOOKUP = 0, /* default - looking rather than defining. */
     VERB,
     ADJ,
     ADV,
     NOUN,
     PREP,
     PRON,
     CONJ
} WORD_TYPE;

void add_word(WORD_TYPE type, char *word);
WORD_TYPE lookup_word(char *word);
