#include "panic.hpp"

int main() {
    panic_when(1 != 1);
    panic_when(1 != 1, "should not panic");
    return 0;
}
