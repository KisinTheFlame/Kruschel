#ifndef _STR_H_
#define _STR_H_

#include <stddef.h>
#include <stdbool.h>

struct Str {
    const char* string;
    size_t length;
};

const struct Str* StrEmpty();

const struct Str* StrNew(const char* s);

void StrFree(const struct Str* str);

const struct Str* StrConcat(const struct Str* s, const struct Str* t);

int StrCompare(const struct Str* s, const struct Str* t);

size_t StrIndexOf(const struct Str* s, char target);

bool StrContains(const struct Str* s, const struct Str* target);

#endif