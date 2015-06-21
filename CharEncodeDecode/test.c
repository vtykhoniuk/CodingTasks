#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "encdecchar.h"

#define ENCODE_SEQ  "%20"

#define BUFFER_SIZE 1024

#define S1  "Hello, World!"
#define SE1 "Hello,%20World!"

#define S2  "   123"
#define SE2 "%20%20%20123"

#define S3  "123   "
#define SE3 "123%20%20%20"

#define S4  "1 "
#define SE4 "1%20"

int main()
{
    char s[BUFFER_SIZE];
    memset(s, '\0', BUFFER_SIZE);

    strcpy(s, S1);
    char_encode(s, ' ', ENCODE_SEQ);
    assert(strcmp(s, SE1) == 0);

    strcpy(s, S2);
    char_encode(s, ' ', ENCODE_SEQ);
    assert(strcmp(s, SE2) == 0);

    strcpy(s, S3);
    char_encode(s, ' ', ENCODE_SEQ);
    assert(strcmp(s, SE3) == 0);

    strcpy(s, SE1);
    char_decode(s, ' ', ENCODE_SEQ);
    assert(strcmp(s, S1) == 0);

    strcpy(s, SE2);
    char_decode(s, ' ', ENCODE_SEQ);
    assert(strcmp(s, S2) == 0);

    strcpy(s, SE3);
    char_decode(s, ' ', ENCODE_SEQ);
    assert(strcmp(s, S3) == 0);

    strcpy(s, SE4);
    char_decode(s, ' ', ENCODE_SEQ);
    assert(strcmp(s, S4) == 0);

    exit(EXIT_SUCCESS);
}
