#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "reverse.h"

#define S1  "Vladimir"
#define S2  "Hello, World!"

#define BUFFER_SIZE 1024

int main()
{
    char s[BUFFER_SIZE];
    memset(s, '\0', BUFFER_SIZE);

    strncpy(s, S1, BUFFER_SIZE);
    reverse(s, 0, strlen(s)-1);
    assert(strcmp(s, "rimidalV") == 0);

    strncpy(s, S2, BUFFER_SIZE);
    reverse_words(s);
    assert(strcmp(s, "World! Hello,") == 0);

    s[0] = '\0';
    reverse_words(s);
    assert(strcmp(s, "") == 0);

    s[0] = ' ';
    s[1] = 'a';
    s[2] = '\0';
    reverse_words(s);
    assert(strcmp(s, "a ") == 0);

    s[0] = 'a';
    s[1] = 'a';
    s[2] = '\0';
    reverse_words(s);
    assert(strcmp(s, "aa") == 0);

    exit(EXIT_SUCCESS);
}
