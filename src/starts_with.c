#include "include.h"

static int starts_with(const string_t *s, const char *prefix);

// Function to check if the string starts with a given substring
static int starts_with(const string_t *s, const char *prefix)
{
    size_t len = 0;

    if (!s->str)
        return 0;
    len = strlen(prefix);
    return strncmp(s->str, prefix, len) == 0;
}