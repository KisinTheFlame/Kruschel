#include "str.h"
#include "panic.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static const struct Str EMPTY_STR = { "", 0 };

inline const struct Str* StrEmpty() {
    return &EMPTY_STR;
}

const struct Str* StrNew(const char* s) {
    size_t length = strlen(s);
    // guarentee that the final string is on the heap
    char* string = malloc(length + 1);
    strcpy(string, s);
    struct Str* p = malloc(sizeof(struct Str));
    p->length = length;
    p->string = string;
    panic_when(p == NULL);
    return p;
}

inline void StrFree(const struct Str* str) {
    free((void*)str->string);
    free((void*)str);
}

inline const struct Str* StrConcat(const struct Str* s, const struct Str* t) {
    size_t length = s->length + t->length;
    char string[length + 1];
    strcpy(string, s->string);
    strcpy(string + s->length, t->string);
    return StrNew(string);
}

inline int StrCompare(const struct Str* s, const struct Str* t) {
    return strcmp(s->string, t->string);
}

inline size_t StrIndexOf(const struct Str* s, char target) {
    for (int i = 0; i < s->length; i++) {
        if (s->string[i] == target) {
            return i;
        }
    }
    return -1;
}

inline bool StrContains(const struct Str* s, const struct Str* target) {
    return strstr(s->string, target->string) != NULL;
}
