/* extern var application */
extern unsigned long int charCount;
extern unsigned long int wordCount;
extern unsigned long int lineCount;

/* extern var library */
extern FILE *yyin;
int yywrap(void);

#ifndef DEBUG
#define DEBUG 0
#endif
extern int debug;
