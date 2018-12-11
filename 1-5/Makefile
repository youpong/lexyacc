CC = clang
CFLAGS = -g -Wall -DDEBUG=0 -std=c11 -D_POSIX_C_SOURCE=200809L
LIBS = -ll

LEX = lex

all:   word-h0 word-h1 word-m
check: word-h0 word-h1 word-m
	sh test.sh
clean:
	- rm -f *.o lex.yy.[ch]  word-h[01] word-m my_lex.c

word-h0: ch1-07.c
	cp ch1-07.c my_lex.c
	make word-h
	mv word-h word-h0
word-h1:
	cp ch1-07-1.c my_lex.c
	make word-h
	mv word-h word-h1

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
