CC = gcc
CFLAGS = -Wall
DEBUG = -DDEBUG=0

all: comment
clean:
	- rm -f comment *.o lex.yy.[ch]
check: comment
	./test.sh

comment: lex.yy.o main.o
	$(CC) -o comment lex.yy.o main.o -ll
main.o: main.h lex.yy.h
lex.yy.o: lex.yy.c main.h
	$(CC) -c lex.yy.c $(CFLAGS) $(DEBUG)
lex.yy.c: lex.l
	$(LEX) --header-file=lex.yy.h lex.l
