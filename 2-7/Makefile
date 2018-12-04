CC = gcc
CFLAGS = -Wall -g
DEBUG = -DDEBUG=0

TARGET = code_counter
OBJS = lex.yy.o main.o 
LIBS = -ll

TEST_TARGET = test
TEST_OBJS = test.o test_yylex.o lex.yy.o
TEST_LIBS = -lcunit -ll

all: $(TARGET)
check: $(TEST_TARGET)
	./$(TEST_TARGET)
clean:
	- rm -f $(TARGET) $(OBJS) $(TEST_TARGET) $(TEST_OBJS) lex.yy.c lex.yy.h

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

$(TEST_TARGET): $(TEST_OBJS)
	$(CC) -o $@ $(TEST_OBJS) $(TEST_LIBS)

lex.yy.h lex.yy.c: lex.l
	$(LEX) --header-file=lex.yy.h $<

main.o: lex.yy.h
$(OBJS): main.h 

test.o test_yylex.o: main.h test.h

.c.o:
	$(CC) -c $< $(CFLAGS) $(DEBUG)
