CC              = cc
CFLAGS          = -std=c99 -I. -I/usr/local/include -O1 -Wall -D_XOPEN_SOURCE=700
LDFLAGS         = -L/usr/local/lib
LDLIBS          = -lcerror

.PHONY : all clean
.DEFAULT_GOAL = all

BINS            = permutation

all: $(BINS)

clean:
	rm -f $(OBJS) $(BINS)
