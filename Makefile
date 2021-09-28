CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -Werror -g

all: test

test: test.o io.o
	$(CC) -o test test.o

test.o:	test.c
	$(CC) $(CLFAGS) -c test.c

io.o:	io.c
	$(CC) $(CLFAGS) -c io.c

