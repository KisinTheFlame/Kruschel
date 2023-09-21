#include "str.h"
#include <assert.h>
#include <string.h>

int factorial(int x) {
    if (x == 0) {
        return 1;
    }
    return x * factorial(x - 1);
}

const struct Str* get_str() {
    char s[20];
    s[0] = 'h';
    s[1] = 'e';
    s[2] = 'l';
    s[3] = 'l';
    s[4] = 'o';
    s[5] = '\0';
    const struct Str* str = StrNew(s);
    return str;
}

int main() {
    const struct Str* s = get_str();
    factorial(20); // modify the program stack
    assert(strcmp(s->string, "hello") == 0);
    assert(s->length == 5);

    const struct Str* t = StrNew("world");
    const struct Str* concat = StrConcat(s, t);
    assert(strcmp(concat->string, "helloworld") == 0);
    assert(concat->length == 10);

    const struct Str* another_s = StrNew("hello");
    assert(StrCompare(s, another_s) == 0);

    assert(StrIndexOf(s, 'e') == 1);
    assert(StrIndexOf(s, 'p') == -1);

    assert(StrContains(s, StrNew("el")));
    assert(!StrContains(s, t));

    StrFree(s);
    StrFree(t);
    StrFree(another_s);

    return 0;
}
