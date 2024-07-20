#include "include.h"

static string_t *replace(string_t *s, const char *old_sub, const char *new_sub);

// Function to replace all occurrences of a substring
static string_t *replace(string_t *s, const char *old_sub, const char *new_sub)
{
    if (!s->str || !old_sub || !new_sub) {
        return s;
    }

    size_t old_len = strlen(old_sub);
    size_t new_len = strlen(new_sub);

    if (old_len == 0) {
        return s;
    }

    size_t count = 0;
    char *tmp = s->str;
    while ((tmp = strstr(tmp, old_sub))) {
        count++;
        tmp += old_len;
    }

    if (count == 0) {
        return s;
    }

    size_t new_str_len = strlen(s->str) + count * (new_len - old_len);
    char *result = malloc(new_str_len + 1);
    if (!result) {
        return s;
    }

    char *current_pos = result;
    tmp = s->str;
    char *next_occurrence;

    while ((next_occurrence = strstr(tmp, old_sub))) {
        size_t segment_len = next_occurrence - tmp;
        memcpy(current_pos, tmp, segment_len);
        current_pos += segment_len;
        memcpy(current_pos, new_sub, new_len);
        current_pos += new_len;
        tmp = next_occurrence + old_len;
    }
    strcpy(current_pos, tmp);

    free(s->str);
    s->str = result;

    return s;
}