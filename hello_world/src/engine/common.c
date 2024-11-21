#include "common.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void ng_die(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    // Just print out the supplied message with an informative prefix
    fprintf(stderr, "{engine fatal} ");
    vfprintf(stderr, format, args);
    fprintf(stderr, "\n");
    
    va_end(args);
    exit(EXIT_FAILURE);
}

int ng_random_int_in_range(int start, int end)
{
    // Remember (`man 3 rand`): rand() returns an integer in [0, RAND_MAX]
    // RAND_MAX is usually defined as a really large number
    return start + rand() % (end - start + 1);
}

bool ng_random_bool(void)
{
    return rand() % 2;
}
