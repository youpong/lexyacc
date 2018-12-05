#include "lex.yy.h"
#include <stdlib.h>

int
main(int argc, char* argv[])
{
	yylex();

	return EXIT_SUCCESS;
}
