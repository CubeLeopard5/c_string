#include "include.h"

static size_t copy_c(const string_t *this, char *s, size_t n, size_t pos);
static size_t copy_s(const string_t *this, const string_t *str, size_t n, size_t pos);

static size_t copy_c(const string_t *this , char *s, size_t n, size_t  pos)
{
    if (pos > strlen(this->str))
        pos = strlen(this->str);
    if (n > strlen(this->str)) {
        n = strlen(this->str + pos) + 1;
        strncpy(s, this->str + pos, n);
        return strlen(s);
    }
    strncpy(s, this->str + pos, n);
    s[n] = '\0';
    return strlen(s);
}

static size_t copy_s(const string_t *this, const string_t *str, size_t n, size_t pos)
{
    if (pos > strlen(this->str))
        pos = strlen(this->str);
    if (n > strlen(this->str)) {
        n = strlen(this->str + pos) + 1;
        strncpy(str->str, this->str + pos, n);
        return strlen(str->str);
    }
    strncpy(str->str, this->str + pos, n);
    str->str[n] = '\0';
    return strlen(str->str);
}