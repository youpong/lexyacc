extern char **targv;
extern char **arglim;

extern char *progName;
extern unsigned int verbose;
extern unsigned int fname;

int myinput(char *buf, int max);
#undef YY_INPUT
#define YY_INPUT(buf,result,max) (result = myinput(buf,max))
