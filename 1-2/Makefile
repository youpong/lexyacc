CC = gcc
CFLAGS = -Wall
LEX = lex

TARGET = word
OBJS = lex.yy.o main.o
LIBS = -ll

all: $(TARGET)
clean:
	- rm -f lex.yy.c $(OBJS) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

lex.yy.c : lex.l
	$(LEX) --header-file=lex.yy.h lex.l
main.o: lex.yy.h

.c.o:
	$(CC) -c $< $(CFLAGS)
