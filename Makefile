CC = gcc
CFLAGS = -Wall -I./include

SRC = src/card.c
TEST = test/test_card.c test/all_tests.c
HEADERS = include/card.h test/test_utils.h

all_tests: $(SRC) $(TEST) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC) $(TEST) -o all_tests

test: all_tests
	./all_tests

clean:
	rm -f all_tests
