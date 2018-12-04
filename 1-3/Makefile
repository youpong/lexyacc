CC = gcc
CFLAGS = -Wall -g
LIBS = -ll

LEX = lex

TARGET = word
OBJS = lex.yy.o lib.o

all: $(TARGET)

clean:
	- rm -f lex.yy.c $(OBJS) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

$(OBJS): main.h

lex.yy.c: lex.l
	$(LEX) lex.l

.c.o:
	$(CC) -c $< $(CFLAGS)
