CC = gcc
CFLAGS = -Wall -g
LIBS = -ly -ll

LEX = lex
YACC = yacc

TARGET = word
OBJS = y.tab.o lex.yy.o lib.o

all: $(TARGET)
clean:
	- rm -f y.tab.c y.tab.h lex.yy.c $(OBJS) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

y.tab.o: lex.yy.h
lex.yy.o: main.h y.tab.h
lib.o: main.h

lex.yy.h lex.yy.c : lex.l
	$(LEX) --header-file=lex.yy.h lex.l
y.tab.h y.tab.c: parse.y
	$(YACC) -d parse.y

.c.o:
	$(CC) -c $< $(CFLAGS)
