#include "include.h"

static string_t *to_upper(string_t *s);

// Function to convert the string to uppercase
static string_t *to_upper(string_t *s)
{
    if (!s->str)
        return s;
    for (char *temp = s->str; *temp; ++temp) {
        *temp = toupper((unsigned char)*temp);
    }
    return s;
}