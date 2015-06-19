CFLAGS=-I$(INCDIR) -O1 -Wall -Werror -std=c99

all: build
	./test

build: test.c trim.h
	$(CC) -o test $< $(CFLAGS)

clean:
	rm ./test
