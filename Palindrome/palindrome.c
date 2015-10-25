#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "palindrome.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Invalid argument\n");
        fprintf(stderr, "Usage: %s <word>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("[%s] is %s\n", argv[1], is_palindrome(argv[1]) ? "a palindrome" : "not a palindrome");

    exit(EXIT_SUCCESS);
}
