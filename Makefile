CC = gcc
CFLAGS = -Wall -I./include

SRC = src/card.c src/deck.c src/tournament.c src/game.c $(wildcard bots/*.c)
TEST = test/all_tests.c test/test_card.c test/test_deck.c test/test_tournament.c
HEADERS = test/test_utils.h include/card.h include/deck.h include/tournament.h include/bots.h

all_tests: $(SRC) $(TEST) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC) $(TEST) -o all_tests

test: all_tests
	./all_tests

main: $(SRC) $(HEADERS) src/main.c
	$(CC) $(CFLAGS) $(SRC) src/main.c -o main

clean:
	rm -f all_tests main
