#ifndef _PANIC_HELPER_HPP_
#define _PANIC_HELPER_HPP_

#include <string>

void __panic_on_with_message(bool expression, const char* message);

void __panic_on_with_message(bool expression, const std::string message);

#define __panic_on_without_message(expression) \
    do { \
        if (expression) { \
            panic("panic when " #expression); \
        } \
    } while (0)

#define __panic_on_select(_0, _1, NAME, ...) NAME

#endif
