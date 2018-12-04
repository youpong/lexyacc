CC = gcc
CFLAGS = -Wall -g -DYYDEBUG=1 -DDEBUG=0

TARGET = cl
OBJS = lex.yy.o main.o 
LIBS = -ll

TEST_TARGET = test
TEST_OBJS = test.o test_func.o
TEST_LIBS = -lcunit

all: $(TARGET)
check: $(TEST_TARGET)
	./$(TEST_TARGET)
clean:
	- rm -f $(TARGET) $(OBJS) $(TEST_TARGET) $(TEST_OBJS) lex.yy.c

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)
$(TEST_TARGET): $(TEST_OBJS)
	$(CC) -o $@ $(TEST_OBJS) $(TEST_LIBS)

lex.yy.c: lex.l
	$(LEX) $<

$(OBJS): main.h
$(TEST_OBJS): main.h test.h

.c.o:
	$(CC) -c $< $(CFLAGS)
