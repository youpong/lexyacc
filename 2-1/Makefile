CC = gcc
CFLAGS = -Wall
DEBUG = -DDEBUG=0

all: num
clean:
	- rm -f num lex.yy.o lex.yy.c

num: lex.yy.o
	$(CC) -o num lex.yy.o -ll
lex.yy.o: lex.yy.c
	$(CC) -c lex.yy.c $(CFLAGS) $(DEBUG)
lex.yy.c: lex.l
	$(LEX) lex.l
