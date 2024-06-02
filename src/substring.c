#include "include.h"

static string_t substring(string_t *s, size_t start, size_t length);

// Function to extract a substring
static string_t substring(string_t *s, size_t start, size_t length)
{
    string_t result;

    string_init(&result, "");

    if (!s->str || start >= strlen(s->str)) {
        return result;
    }
    if (start + length > strlen(s->str)) {
        length = strlen(s->str) - start;
    }
    result.str = malloc(length + 1);
    if (!result.str) {
        return result;
    }
    strncpy(result.str, s->str + start, length);
    result.str[length] = '\0';
    return result;
}