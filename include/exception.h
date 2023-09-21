#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include "panic.h"

#define try(expression) \
    do { \
        int r = (expression); \
        if (r != 0) { \
            return r; \
        } \
    } while (0)

#endif
