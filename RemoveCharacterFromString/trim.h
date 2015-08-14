#ifndef TRIM_H
#define TRIM_H

#include <stddef.h>
#include <string.h>

// Removes all characters 'c' from string 'a'
// The idea is to keep two pointers:
//   i - points to the currently processing character
//   j - points to the place where character could be moved to
void trim(char* a, size_t N, const char c)
{
    int i =  0, j = 0;
    for (; i < N; ++i) {
        if (a[i] == c)  continue;
        a[j++] = a[i];
    }

    a[j] = '\0';
}

// Removes all characters represented by set 's' from string 'a'
void trimm(char* a, size_t N, const char* s)
{
    int i =  0, j = 0;
    const char* c;

    for (; i < N; ++i) {
        c = s;
        while (*c != '\0' && a[i] != *c)    ++c;
        if (*c != '\0')   continue;

        a[j++] = a[i];
    }

    a[j] = '\0';
}

// Removes all dublicates from a sorted array
void trim_sorted(char* a, size_t N)
{
    if (N == 0)
        return;

    int i = 0, j = 0;
    char c = a[i];

    for (; i < N; ++i) {
        if (a[i] == c)  continue;
        a[j++] = c;
        c = a[i];
    }

    a[j++] = c;
    a[j] = '\0';
}

#endif // TRIM_H
