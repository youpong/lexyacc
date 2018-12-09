int yyerror(const char *);
extern int yydebug;

#define LOOKUP 0

int add_word(int type, char *word);
int lookup_word(char *word);
