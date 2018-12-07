CC = clang
CFLAGS = -Wall -g -std=c11 -DYYDEBUG=1 -DDEBUG=0 -D_POSIX_C_SOURCE=200809L

TARGET = cl
OBJS = lex.yy.o y.tab.o main.o 
LIBS = -ly -ll 

TEST_TARGET = test
TEST_OBJS = test.o test_func.o
TEST_LIBS = -lcunit

all: cl0 cl1 cl2

check: $(TEST_TARGET)
	./$(TEST_TARGET)
	./test.sh
clean:
	- rm -f $(TARGET) $(OBJS) $(TEST_TARGET) $(TEST_OBJS) \
                lex.yy.[ch] y.tab.[ch] cl[012]
cl0:
	cp main0.c main.c
	make cl
	mv cl cl0
cl1:
	cp main1.c main.c
	make cl
	mv cl cl1
cl2:
	cp main2.c main.c
	make cl
	mv cl cl2

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
