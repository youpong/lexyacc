CC = gcc
CFLAGS = -Wall -g -std=c11 -D_POSIX_C_SOURCE=200809L
LIBS = -ll

LEX = lex

TARGET = word
OBJS = lex.yy.o lib.o main.o

all: $(TARGET)

clean:
	- rm -f lex.yy.[ch] $(OBJS) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

$(OBJS): main.h lex.yy.h

lex.yy.h lex.yy.c: ch1-04.l
	$(LEX) --header-file=lex.yy.h ch1-04.l

.c.o:
	$(CC) -c $< $(CFLAGS)
