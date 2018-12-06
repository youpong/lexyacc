CC = clang
CFLAGS = -Wall -g -DYYDEBUG=1 -DDEBUG=0

TARGET = cl
OBJS = lex.yy.o y.tab.o main.o 
LIBS = -ly -ll 

TEST_TARGET = test
TEST_OBJS = test.o test_func.o
TEST_LIBS = -lcunit

all: $(TARGET)
check: $(TEST_TARGET)
	./$(TEST_TARGET)
clean:
	- rm -f $(TARGET) $(OBJS) $(TEST_TARGET) $(TEST_OBJS) \
                lex.yy.[ch] y.tab.[ch]

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)
$(TEST_TARGET): $(TEST_OBJS)
	$(CC) -o $@ $(TEST_OBJS) $(TEST_LIBS)

y.tab.h y.tab.c: parse.y
	$(YACC) -d $<
lex.yy.c lex.yy.h: lex.l
	$(LEX) --header-file=lex.yy.h $<

y.tab.o: lex.yy.h
lex.yy.o: y.tab.h
$(OBJS): main.h
$(TEST_OBJS): main.h test.h

.c.o:
	$(CC) -c $< $(CFLAGS)
