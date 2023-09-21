#ifndef _PANIC_H_
#define _PANIC_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define panic(message) \
    do { \
        if (strcmp(message, "") != 0) { \
            printf(message "\n"); \
        } \
        exit(1); \
    } while (0)

#define panic_when(expression) \
    do { \
        if (expression) { \
            panic("panic when " #expression); \
        } \
    } while (0)

#endif
