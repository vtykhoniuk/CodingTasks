#ifndef PACKSTRING_H
#define PACKSTRING_H

#include "CArray.h"

#define EOS '\0'
#define BUFFER_SIZE 1024

size_t calculatePackSize(const char* s)
{
    size_t size = 0;
    size_t count;

    while (*s != EOS) {
        ++size;

        count = 1;
        for (const char* c = s+1; *c != EOS && *c++ == *s; ++count);
        s += count;

        do {
            ++size;
        } while (count /= 10);
    }

    return size;
}

char* pack_string(const char* s)
{
    size_t N = strlen(s);
    size_t pN = calculatePackSize(s);
    size_t count;
    char* result = NULL;
    char b[BUFFER_SIZE];
    memset(b, '\0', BUFFER_SIZE);

    if (N > pN) {
        result = (char*) malloc(pN+1 * sizeof(char));
        result[pN] = EOS;

        char* ps = result;
        while (*s != EOS) {
            *ps++ = *s++;

            count = 1;
            for (const char* c = s+1; *c != EOS && *c++ == *s; ++count);
            s += count;

            snprintf(b, BUFFER_SIZE-1, "%ld", count);
            strcpy(ps, b);
        }
    }

    return result;
}

#endif // PACKSTRING_H
