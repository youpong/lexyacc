CC = gcc
CFLAGS = -Wall -g
LEX = lex

TARGET = echo0 echo1 echo2
LIBS = -ll

all: $(TARGET)
check: $(TARGET)
	sh test.sh
clean:
	- rm -f lex[012].yy.c lex[012].yy.o echo[012]

echo0: lex0.yy.o
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)
echo1: lex1.yy.o
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)
echo2: lex2.yy.o
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

lex0.yy.c : lex0.l
	$(LEX) -o $@ $<
lex1.yy.c : lex1.l
	$(LEX) -o $@ $<
lex2.yy.c : lex2.l
	$(LEX) -o $@ $<
