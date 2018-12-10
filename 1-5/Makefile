CC = clang
CFLAGS = -g -Wall -DDEBUG=0 -std=c11 -D_POSIX_C_SOURCE=200809L
LIBS = -ll

LEX = lex

all: word-h word-m
check: word-h word-m
	sh test.sh
clean:
	- rm -f *.o lex.yy.[ch]  word-h word-m

word-h: my_lex.o main.o
	$(CC) -o $@ my_lex.o main.o

word-m: lex.yy.o main.o
	$(CC) -o $@ lex.yy.o main.o $(LIBS)

lex.yy.o my_lex.o: word.h
main.o my_lex.o: lex.yy.h

lex.yy.c lex.yy.h: ch1-07.l
	$(LEX) --header-file=lex.yy.h ch1-07.l
.c.o:
	$(CC) -c $< $(CFLAGS)
