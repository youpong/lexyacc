CC = gcc
CFLAGS = -Wall -g
DEBUG = -DDEBUG=0

TARGET = wc
OBJS = lex.yy.o main.o
LIBS = 

all: $(TARGET)
clean:
	- rm -f $(TARGET) $(OBJS) lex.yy.c lex.yy.h

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)
lex.yy.h lex.yy.c: lex.l
	$(LEX) --header-file=lex.yy.h $<

lex.yy.o main.o: main.h
main.o: lex.yy.h

.c.o:
	$(CC) -c $< $(CFLAGS) $(DEBUG)
