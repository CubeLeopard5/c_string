#include "include.h"

static string_t *split(string_t *s, const char delimiter, size_t *count);

// Function to split the string into an array of string_t based on a delimiter
static string_t *split(string_t *s, const char delimiter, size_t *count)
{
    if (!s->str) {
        *count = 0;
        return NULL;
    }
    size_t segments = 1;
    for (char *temp = s->str; *temp; ++temp) {
        if (*temp == delimiter) {
            ++segments;
        }
    }
    string_t *result = malloc(segments * sizeof(string_t));
    if (!result) {
        return NULL;
    }
    *count = segments;
    char *start = s->str;
    size_t segment_index = 0;
    for (char *temp = s->str; ; ++temp) {
        if (*temp == delimiter || *temp == '\0') {
            size_t length = temp - start;
            result[segment_index].str = malloc(length + 1);
            if (!result[segment_index].str) {
                return NULL;
            }
            strncpy(result[segment_index].str, start, length);
            result[segment_index].str[length] = '\0';
            ++segment_index;
            if (*temp == '\0')
                break;
            start = temp + 1;
        }
    }
    return result;
}