typedef enum {
  LOOKUP = 0, /* default - looking rather than defining. */
  VERB = 256,
  ADJ,
  ADV,
  NOUN,
  PREP,
  PRON,
  CONJ,
} WORD_TYPE;

extern WORD_TYPE state;

typedef struct word {
  WORD_TYPE type;
  char *name;
  struct word *next;
} WORD;

void add_word(WORD_TYPE, char *);
WORD_TYPE lookup_word(char *);
