CC = clang
CFLAGS = -Wall -g -std=c11 -D_POSIX_C_SOURCE=200809L
LIBS = -ly -ll

LEX = lex
YACC = yacc

TARGET = word
OBJS = y.tab.o lex.yy.o main.o lib.o

all: $(TARGET)
clean:
	- rm -f y.tab.c y.tab.h lex.yy.c $(OBJS) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

y.tab.o: lex.yy.h
lex.yy.o: y.tab.h
lex.yy.o main.o lib.o: main.h

lex.yy.h lex.yy.c : ch1-05.l
	$(LEX) --header-file=lex.yy.h ch1-05.l
y.tab.h y.tab.c: parse.y
	$(YACC) -d parse.y

.c.o:
	$(CC) -c $< $(CFLAGS)
