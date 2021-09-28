CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -Werror -g

all: test

test: test.o io.o
	$(CC) -o test test.io

io.o:	io.c
	$(CC) $(CLFAGS) -c io.c

