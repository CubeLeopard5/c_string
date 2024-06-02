#include "include.h"

static int ends_with(string_t *s, const char *suffix);

// Function to check if the string ends with a given substring
static int ends_with(string_t *s, const char *suffix)
{
    size_t len = 0;
    size_t str_len = 0;

    if (!s->str)
        return 0;
    len = strlen(suffix);
    str_len = strlen(s->str);
    if (len > str_len)
        return 0;
    return strncmp(s->str + str_len - len, suffix, len) == 0;
}