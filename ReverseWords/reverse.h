#ifndef REVERSE_H
#define REVERSE_H

#include "CArray.h"
#include <ctype.h>

// Reverses characters in string 's' between positions 'i' and 'j'
void reverse(char* s, int i, int j)
{
    while (i < j)
        swap(s, sizeof(char), i++, j--);
}

// Reverses words from sting 's'
// For example: "Hello, World!" => "World! Hello,"
void reverse_words(char* s)
{
    int i, j;

    // Reverse each word in the string
    i = 0, j = 0;
    while (1) {
        // Set 'i' to point at the beginning of new word
        while (s[i] != '\0' && isspace(s[i]))   ++i;

        // We are done if EOS reached
        if (s[i] == '\0')   break;

        // Set 'j' to point at the end of the word
        j = i+1;
        while (s[j] != '\0' && !isspace(s[j]))   ++j;
        --j;

        // Reverse the word s[i, j]
        reverse(s, i, j);

        i = j+1;
    }

    // Reverse the whole string
    reverse(s, 0, strlen(s)-1);
}

#endif // REVERSE_H
