#include "permutation.h"

#include "cerror.h"

#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 2)
        err_quit("Usage: %s <STRING>", argv[0]);

    size_t n = strlen(argv[1]);
    permutation(argv[1], 0, n-1);

    exit(EXIT_SUCCESS);
}
