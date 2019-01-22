CC = gcc
CFLAGS = -Wall -g -DYYDEBUG=1 -DDEBUG=0 -D_POSIX_C_SOURCE=200809L

TARGET = cl
OBJS = lex.yy.o y.tab.o main.o 
LIBS = -ll -ly

TEST_TARGET = test
TEST_OBJS = test.o test_func.o
TEST_LIBS = -lcunit

all: $(TARGET)
check: $(TEST_TARGET)
	./$(TEST_TARGET)
clean:
	- rm -f $(TARGET) $(OBJS) $(TEST_TARGET) $(TEST_OBJS) \
                y.tab.[ch] lex.yy.[ch] a.out
format:
	clang-format -i *.[ch]
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)
$(TEST_TARGET): $(TEST_OBJS)
	$(CC) -o $@ $(TEST_OBJS) $(TEST_LIBS)

$(OBJS): main.h
$(TEST_OBJS): main.h test.h

# YACC/LEX
y.tab.o: lex.yy.h
lex.yy.o: y.tab.h
y.tab.c y.tab.h: parse.y
	$(YACC) -d $<
lex.yy.c lex.yy.h: lex.l
	$(LEX) --header-file=lex.yy.h $<



.c.o:
	$(CC) -c $< $(CFLAGS)
