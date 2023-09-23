#ifndef _PANIC_HPP_
#define _PANIC_HPP_

#include "panic_helper.hpp"
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>

void panic(const char* message);

void panic(const std::string message);

#define panic_when(...) __panic_on_select(__VA_ARGS__, __panic_on_with_message, __panic_on_without_message)(__VA_ARGS__)

#endif
