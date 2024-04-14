#include "./string.h"

static size_t copy(const string_t *this, char *s, size_t n, size_t pos);

static size_t copy(const string_t *this , char *s, size_t n, size_t  pos)
{
    if (pos > strlen(this->str))
        pos = strlen(this->str);
    if (n > strlen(this->str)) {
        n = strlen(this->str + pos) + 1;
        strncpy(s, this->str + pos, n);
        return strlen(s) + 1;
    }
    strncpy(s, this->str + pos, n);
    s[n] = '\0';
    return strlen(s);
}