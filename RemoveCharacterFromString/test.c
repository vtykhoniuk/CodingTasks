#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "trim.h"

#define S1  "Vladimir"
#define S2  "vvvvvvvv"
#define S3  "11223344"
#define S4  "12345678"

int main()
{
    size_t N = strlen(S1);
    char* s = (char *) malloc(N);
    memcpy(s, S1, N);

    trim(s, N, 'i');
    assert(strcmp(s, "Vladmr") == 0);

    trim(s, N, 'a');
    assert(strcmp(s, "Vldmr") == 0);

    trim(s, N, 'x');
    assert(strcmp(s, "Vldmr") == 0);

    trimm(s, N, "ld");
    assert(strcmp(s, "Vmr") == 0);

    memcpy(s, S1, N);
    trimm(s, N, "ai");
    assert(strcmp(s, "Vldmr") == 0);

    memcpy(s, S2, N);
    trim(s, N, 'v');
    assert(strcmp(s, "") == 0);

    memcpy(s, S2, N);
    trim(s, N, 'a');
    assert(strcmp(s, S2) == 0);

    memcpy(s, S3, N);
    trim_sorted(s, N);
    assert(strcmp(s, "1234") == 0);

    memcpy(s, S4, N);
    trim_sorted(s, N);
    assert(strcmp(s, S4) == 0);

    printf("Tests passed\n");
    free(s);

    exit(EXIT_SUCCESS);
}
