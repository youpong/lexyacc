CC = gcc
CFLAGS = -Wall -g
DEBUG = -DDEBUG=0

TARGET = cl
OBJS = lex.yy.o main.o myinput.o
LIBS = -ll

TEST_TARGET = test
TEST_OBJS = myinput.o test_myinput.o test.o
TEST_LIBS = -lcunit

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

$(OBJS): main.h
main.o: lex.yy.h
test.o test_myinput.o: main.h test.h

.c.o:
	$(CC) -c $< $(CFLAGS) $(DEBUG)
