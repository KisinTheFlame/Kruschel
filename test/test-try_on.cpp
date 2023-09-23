#include "exception.hpp"

int f() {
    return 0;
}

int main() {
    try_on(0);
    try_on(f());
    return 0;
}
