#ifndef PALINDROME_H
#define PALINDROME_H

#include <assert.h>

bool is_palindrome(const char *str)
{
    const char *i, *j;
    i = j = str;

    // Moving j to point to last symbol of str
    while (*j != '\0') ++j; --j;

    // Empty string assertion
    assert(j >= i);

    // Move i from left to right and j from
    // right to left till either pointers
    // contain different characters or they
    // cross
    while (*i == *j && j-- > i++);

    // If we exit 'while' above having 'i'
    // passed 'j' - the word is palindrome
    return j < i;
}

#endif // PALINDROME_H
