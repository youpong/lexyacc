CC = gcc
CFLAGS = -Wall -g
LEX = lex

TARGET = echo
LIBS = -ll

all: echo0 echo1 echo2

echo0: ch1-01.l
	cp ch1-01.l lex.l
	make echo
	mv echo echo0
echo1: lex1.l
	cp lex1.l lex.l
	make echo
	mv echo echo1
echo2: lex2.l
	cp lex2.l lex.l
	make echo
	mv echo echo2

check: echo0 echo1 echo2
	sh test.sh
clean:
	- rm -f lex.yy.c lex.yy.o echo[012] lex.l

echo: lex.yy.o
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

lex.yy.c : lex.l
	$(LEX) -o $@ $<
