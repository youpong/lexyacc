CC = gcc
CFLAGS = -Wall -g
DEBUG = -DDEBUG=0

TARGET = magic
OBJS = lex.yy.o main.o
LIBS = -ll

TARGET2 = magic2
OBJS2 = lex2.yy.o main.o

all: $(TARGET) $(TARGET2)
clean:
	- rm -f $(TARGET) $(OBJS) $(TARGET2) $(OBJS2) \
	lex.yy.c lex.yy.h lex2.yy.c lex2.yy.h

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)
$(TARGET2): $(OBJS2)
	$(CC) -o $@ $(OBJS2) $(LIBS)

main.o: lex.yy.h lex2.yy.h

lex.yy.h lex.yy.c: lex.l
	$(LEX) --header-file=lex.yy.h $<
lex2.yy.h lex2.yy.c: lex2.l
	$(LEX) --header-file=lex2.yy.h -o lex2.yy.c $< 

.c.o:
	$(CC) -c $< $(CFLAGS) $(DEBUG)
