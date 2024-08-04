#include "include.h"

static string_t select_s(const string_t *s, char c);

string_t select_s(const string_t *s, char c)
{
    int nb = 0;
    char *rtn = NULL;
    size_t j = 0;
    string_t str;

    if (s->str == NULL) {
        string_init(&str, "");
        return str;
    }
    for (size_t i = 0; s->str[i] != '\0'; i++)
        if (s->str[i] == c)
            nb++;
    rtn = malloc(sizeof(char) * (nb + 1));
    for (size_t i = 0; s->str[i] != '\0'; i++) {
        if (s->str[i] == c) {
            rtn[j] = s->str[i];
            j++;
        }
    }
    rtn[j] = '\0';
    string_init(&str, rtn);
    return str;
}