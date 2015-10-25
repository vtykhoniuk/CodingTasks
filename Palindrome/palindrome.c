#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "palindrome.h"

void usage();

int main(int argc, char **argv)
{
    char c;
    bool use_linked_list = false;

    opterr = 0;
    while ((c = getopt(argc, argv, "l")) != EOF) {
        switch (c) {
            case 'l': use_linked_list = true; break;
            default: usage();
        }
    }

    argc -= optind;
    argv += optind;

    if (argc != 1) {
        fprintf(stderr, "Invalid argument\n");
        usage();
    }

    const char *str = argv[0];
    bool is_pal = false;

    if (use_linked_list) {
        ADS_LinkedList list = ADS_LinkedList_allocate();
        str2ll(str, list);
        is_pal = is_ll_palindrome(list);
        ADS_LinkedList_destroy(list);
    } else {
        is_pal = is_palindrome(str);
    }

    printf("[%s] is %s\n", str, is_pal ? "a palindrome" : "not a palindrome");

    exit(EXIT_SUCCESS);
}

void usage()
{
    fprintf(stderr, "Usage: palindrome [-l] <word>\n");
    fprintf(stderr, "  -l  convert string to linked list\n");
    exit(EXIT_FAILURE);
}
