#ifndef ENCDECSPACE_H
#define ENCDECSPACE_H

#include "CArray.h"

// Inplace replace all 'c' characters in string 's' with string e
// String s should be large enough
void char_encode(char* s, char c, char* e)
{
    int i = 0;
    int j = 0;
    int char_counter = 0;
    size_t esize = strlen(e);

    // Find all spaces in string
    while (s[i] != '\0')
        if (s[i++] == c)
            ++char_counter;

    // Set i to point at the last character in the string
    --i;

    // Set j to point at the last character of encoded string
    j = i + char_counter * (esize-1);
    s[j+1] = '\0';

    while (char_counter > 0) {
        if (s[i] != c)
            swap(s, sizeof(char), i, j--);
        else {
            --char_counter;
            memcpy(&s[j-(esize-1)], e, esize);
            j -= esize;
        }

        --i;
    }
}

void char_decode(char* s, char c, char* e)
{
    int i, j;
    size_t N = strlen(s);
    size_t elen = strlen(e);

    i = 0, j = 0;
    while (j < N) {
        if (j + elen <= N && memcmp(&s[j], e, elen) == 0) {
            s[i++] = c;
            j += elen;
        } else
            swap(s, sizeof(char), i++, j++);
    }

    s[i] = '\0';
}

#endif // ENCDECSPACE_H
