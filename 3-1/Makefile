CC = cc
CFLAGS = -Wall -g -DYYDEBUG=1
YACC = yacc
LEX = lex

TARGET = calc
OBJS = addfunc.o symlook.o lex.yy.o y.tab.o main.o
LIBS = -ly -ll -lm

all: $(TARGET)

clean:
	- rm -f y.tab.h y.tab.c lex.yy.c lex.yy.h $(OBJS) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

y.tab.c y.tab.h: parse.y
	$(YACC) -d $<
lex.yy.h lex.yy.c: lex.l
	$(LEX) --header-file=lex.yy.h $<

main.o lex.yy.o: y.tab.h
y.tab.o: lex.yy.h
$(OBJS): calc.h

.c.o:
	$(CC) -c $< $(CFLAGS) $(DEBUG)
