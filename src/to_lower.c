#include "include.h"

static string_t *to_lower(string_t *s);

// Function to convert the string to lowercase
static string_t *to_lower(string_t *s)
{
    if (!s->str)
        return s;
    for (char *temp = s->str; *temp; ++temp) {
        *temp = tolower((unsigned char)*temp);
    }
    return s;
}