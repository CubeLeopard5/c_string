#include "include.h"

static int compare_s(const string_t *this, const string_t *str);
static int compare_c(const string_t *this, const char *str);

static int compare_s(const string_t *this, const string_t *str)
{
    return strcmp(this->str, str->str);
}

static int compare_c(const string_t *this, const char *str)
{
    return strcmp(this->str, str);
}