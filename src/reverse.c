#include "include.h"

static string_t *reverse(string_t *s);

// Function to reverse the contents of the string_t
static string_t *reverse(string_t *s)
{
    size_t len = 0;

    if (!s->str)
        return s;
    len = strlen(s->str);
    for (size_t i = 0; i < len / 2; ++i) {
        char temp = s->str[i];
        s->str[i] = s->str[len - 1 - i];
        s->str[len - 1 - i] = temp;
    }
    return s;
}