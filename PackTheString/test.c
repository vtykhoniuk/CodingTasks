#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "packstring.h"

#define S1  "abcd"
#define SP1 8

#define S2  "abcddd"
#define SP2 8

#define S3  "dddddddddd"
#define SP3 3
#define PS3 "d10"

#define S4  "adddddddddd"
#define SP4 5
#define PS4 "a1d10"

#define S5  "addddddddddccccccccccc"
#define SP5 8
#define PS5 "a1d10c11"


int main()
{
    char* s;

    assert(calculatePackSize(S1) == SP1);
    assert(calculatePackSize(S2) == SP2);
    assert(calculatePackSize(S3) == SP3);
    assert(calculatePackSize(S4) == SP4);
    assert(calculatePackSize(S5) == SP5);

    assert(pack_string(S1) == NULL);
    assert(pack_string(S2) == NULL);

    s = pack_string(S3);
    assert(s != NULL);
    assert(strcmp(s, PS3));
    free(s);

    s = pack_string(S4);
    assert(s != NULL);
    assert(strcmp(s, PS4));
    free(s);

    exit(EXIT_SUCCESS);
}
