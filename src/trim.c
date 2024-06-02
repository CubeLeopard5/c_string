#include "include.h"

static string_t *trim(string_t *s);

// Function to remove leading and trailing whitespace
static string_t *trim(string_t *s)
{
    char *start = NULL;
    char *end = NULL;

    if (!s->str)
        return s;
    start = s->str;
    while (isspace((unsigned char)*start))
        ++start;
    end = s->str + strlen(s->str) - 1;
    while (end > start && isspace((unsigned char)*end))
        --end;
    *(end + 1) = '\0';
    if (start > s->str) {
        memmove(s->str, start, end - start + 2);
    }
    return s;
}