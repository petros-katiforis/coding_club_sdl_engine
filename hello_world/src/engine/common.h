#ifndef _NG_COMMON_H
#define _NG_COMMON_H

#include <stdbool.h>

void ng_die(const char *format, ...);

int ng_random_int_in_range(int start, int end);
bool ng_random_bool(void);

#endif
