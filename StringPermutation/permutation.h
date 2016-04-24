#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <stdio.h>

void swap(char *str, int i, int j)
{
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
}

void permutation(char *str, int lo, int hi)
{
    if (lo == hi) {
        puts(str);
        return;
    }

    int i;
    for (i = lo; i <= hi; i++) {
        swap(str, lo, i);
        permutation(str, lo+1, hi);
        swap(str, lo, i);
    }
}

#endif // PERMUTATION_H
