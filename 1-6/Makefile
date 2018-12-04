CC = gcc
CFLAGS = -Wall -DDEBUG=0
LIBS = -ll

LEX = lex

all: word word2
check: word word2
	sh test.sh
clean:
	- rm -f my_lex.o lex.yy.c lex.yy.o word word2

word: my_lex.o
	$(CC) -o $@ $<

word2: lex.yy.o
	$(CC) -o $@ $< $(LIBS)

lex.yy.c: lex.l
	$(LEX) lex.l
.c.o:
	$(CC) -c $< $(CFLAGS)
