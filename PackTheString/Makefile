ifndef LIBPREFIX
    $(warning LIBPREFIX is not set, trying ./)
else
    $(info LIBPREFIX=$(LIBPREFIX))
endif

CFLAGS = -I$(LIBPREFIX)/include -O1 -Wall -Werror -std=c99

all: build
	./test

build: test.c packstring.h
	$(CC) -o test $< $(LIBPREFIX)/lib/libCArray.a $(CFLAGS)

clean:
	rm ./test
