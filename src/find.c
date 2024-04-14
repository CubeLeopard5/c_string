#include "include.h"

static int find_s(const string_t *this, const string_t *str, size_t pos);
static int find_c(const string_t *this, const char *str, size_t pos);

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    if (this->str && (strlen(this->str) > pos))
        if (strstr(&this->str[pos], str->str) != NULL)
            return ((strstr(&this->str[pos], str->str)) - (this->str));
    return -1;
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    if (this->str && (strlen(this->str) > pos))
        if (strstr(&this->str[pos], str) != NULL)
            return ((strstr(&this->str[pos], str)) - (this->str));
    return -1;
}