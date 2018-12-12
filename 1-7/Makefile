CC = gcc
CFLAGS = -Wall
DEBUG = -DDEBUG=0

all: comment
clean:
	- rm -f comment lex.yy.o lex.yy.c
check: comment
	./test.sh

comment: lex.yy.o
	$(CC) -o comment lex.yy.o -ll
lex.yy.o: lex.yy.c
	$(CC) -c lex.yy.c $(CFLAGS) $(DEBUG)
lex.yy.c: lex.l
	$(LEX) lex.l
