#include "panic.hpp"
#include "panic_helper.hpp"
#include <cstring>
#include <iostream>

void panic(const char* message) {
    std::cout << message << std::endl;
    exit(1);
}

void panic(const std::string message) {
    panic(message.c_str());
}

void __panic_on_with_message(bool expression, const char* message) {
    if (expression) {
        panic(message);
    }
}

void __panic_on_with_message(bool expression, const std::string message) {
    __panic_on_with_message(expression, message.c_str());
}
