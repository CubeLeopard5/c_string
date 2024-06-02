#include "include.h"

static string_t *replace(string_t *s, const char *old_sub, const char *new_sub);

// Function to replace all occurrences of a substring
static string_t *replace(string_t *s, const char *old_sub, const char *new_sub)
{
    if (!s->str)
        return s;
    size_t old_len = strlen(old_sub);
    size_t new_len = strlen(new_sub);
    char *result = NULL;
    size_t count = 0;
    char *temp = s->str;
    char *current = NULL;

    while ((temp = strstr(temp, old_sub))) {
        ++count;
        temp += old_len;
    }
    if (count == 0)
        return s;
    result = malloc(strlen(s->str) + (new_len - old_len) * count + 1);
    if (!result) {
        return s;
    }
    current = result;
    temp = s->str;
    while ((temp = strstr(temp, old_sub))) {
        size_t len = temp - s->str;
        strncpy(current, s->str, len);
        current += len;
        strncpy(current, new_sub, new_len);
        current += new_len;
        temp += old_len;
        s->str = temp;
    }
    strcpy(current, s->str);
    free(s->str);
    s->str = result;
    return s;
}