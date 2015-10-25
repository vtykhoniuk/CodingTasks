CC                  = cc
ADS_INC             = /Users/vtykhoniuk/Documents/Development/TOOLCHAIN/include
ADS_LIB             = /Users/vtykhoniuk/Documents/Development/TOOLCHAIN/lib
ADS                 = ads
CFLAGS              = -std=c99 -g -O1 -Wall
CPPFLAGS            = -I. -I${ADS_INC}
LDFLAGS             = -L${ADS_LIB} -l${ADS}

all: palindrome

test:
	valgrind --leak-check=full ./palindrome -l 123321

clean:
	rm palindrome
