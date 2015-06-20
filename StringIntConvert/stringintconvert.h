#ifndef STRINGINTCONVERT_H
#define STRINGINTCONVERT_H

#include <ctype.h>
#include <stdlib.h>
#include "reverse.h"

// Converts string 's' to integer
int stringtoint(const char* s)
{
    int d = 0;
    int sign = 1;

    if (!isdigit(*s)) {
        if (*s == '-')
            sign = -1;
        ++s;
    }

    while (isdigit(*s)) {
        d = d*10 + (*s - '0');
        ++s;
    }

    d *= sign;

    return d;
}

// Converts int to string
void inttostring(int d, char* s)
{
    if (d < 0) {
        *s++ = '-';
        d = abs(d);
    }

    int i = 0;
    do {
        s[i++] = '0' + (d%10);
    } while (d /= 10);

    reverse(s, 0, i-1);

    s[i] = '\0';
}

#endif // STRINGINTCONVERT_H
