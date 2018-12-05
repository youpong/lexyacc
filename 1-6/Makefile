CC = clang
CFLAGS = -Wall -g -std=c11 -D_POSIX_C_SOURCE=200809L
LIBS = -ly -ll

LEX = lex
YACC = yacc

TARGET = word
OBJS = y.tab.o lex.yy.o main.o lib.o

all: word0 
clean:
	- rm -f y.tab.[ch] lex.yy.[ch] parse.y $(OBJS) word0

word0:
	cp ch1-08.y parse.y
	make word
	mv word word0

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

main.o y.tab.o: lex.yy.h
main.o lex.yy.o: y.tab.h
$(OBJS): main.h

lex.yy.h lex.yy.c : ch1-08.l
	$(LEX) --header-file=lex.yy.h ch1-08.l
y.tab.h y.tab.c: parse.y
	$(YACC) -d parse.y

.c.o:
	$(CC) -c $< $(CFLAGS)