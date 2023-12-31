default: main
CC=gcc
SRC=.

main: $(SRC)/big_integer.c  $(SRC)/main.c
	mkdir -p build
	$(CC) -c -o build/big_integer.o  $(SRC)/big_integer.c
	$(CC) -c -o build/main.o  $(SRC)/main.c
	$(CC) -o build/main build/main.o build/big_integer.o

tests: $(SRC)/big_integer.c  $(SRC)/main.c
	mkdir -p build
	$(CC) -c -o build/big_integer.o  $(SRC)/big_integer.c
	$(CC) -c -o build/tests.o  $(SRC)/tests.c
	$(CC) -o build/tests build/tests.o build/big_integer.o
