#ifndef PALINDROME_H
#define PALINDROME_H

#include <assert.h>

bool is_palindrome(const char *str)
{
    const char *i, *j;
    i = j = str;

    while (*j != '\0') ++j; --j;

    assert(j >= i);

    while (*i == *j && j-- > i++);

    return j < i;
}

#endif // PALINDROME_H
