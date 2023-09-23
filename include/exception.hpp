#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include "panic.hpp"

#define try_on(expression) \
    do { \
        int r = (expression); \
        if (r != 0) { \
            return r; \
        } \
    } while (0)

#endif
