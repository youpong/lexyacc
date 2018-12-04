CC = gcc
CFLAGS = -Wall -std=c11 -D_POSIX_C_SOURCE=200809L
LEX = lex

TARGET = word0
OBJS = lex0.yy.o main.o
LIBS = -ll

all: $(TARGET)
clean:
	- rm -f lex0.yy.c lex0.yy.h $(OBJS) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

lex0.yy.c lex0.yy.h: ch1-02.l
	$(LEX) --header-file=lex0.yy.h ch1-02.l
	mv lex.yy.c lex0.yy.c
main.o: lex0.yy.h

.c.o:
	$(CC) -c $< $(CFLAGS)
