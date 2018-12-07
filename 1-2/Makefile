CC = gcc
CFLAGS = -Wall -std=c11 -D_POSIX_C_SOURCE=200809L
LEX = lex

TARGET = word
OBJS = lex.yy.o main.o
LIBS = -ll

all: word0 word1
clean:
	- rm -f lex.l lex.yy.c lex.yy.h $(OBJS) $(TARGET) word0 word1

word0: ch1-02.l
	cp ch1-02.l lex.l
	rm -f lex.yy.c
	make word
	mv word word0
word1: ch1-03.l
	cp ch1-03.l lex.l
	rm -f lex.yy.c
	make word
	mv word word1

check: word0 word1
	./test.sh

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

lex.yy.c lex.yy.h: lex.l
	$(LEX) --header-file=lex.yy.h lex.l
main.o: lex.yy.h

.c.o:
	$(CC) -c $< $(CFLAGS)
