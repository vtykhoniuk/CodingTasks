#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "stringintconvert.h"

#define S1  "1346"
#define D1  1346

#define S2  "-1346"
#define D2  -1346

#define S3  "0"
#define D3  0

#define S4  "+13467"
#define D4  13467

#define BUFFER_SIZE 64

int main()
{
    int d = stringtoint(S1);
    assert(d == D1);

    d = stringtoint(S2);
    assert(d == D2);

    d = stringtoint(S3);
    assert(d == D3);

    d = stringtoint(S4);
    assert(d == D4);

    char s[BUFFER_SIZE];
    memset(s, '\0', BUFFER_SIZE);
    inttostring(D1, s);
    assert(strcmp(s, S1) == 0);

    memset(s, '\0', BUFFER_SIZE);
    inttostring(D2, s);
    assert(strcmp(s, S2) == 0);

    memset(s, '\0', BUFFER_SIZE);
    inttostring(D3, s);
    printf("%s\n", s);
    assert(strcmp(s, S3) == 0);

    printf("Tests passed\n");

    exit(EXIT_SUCCESS);
}
