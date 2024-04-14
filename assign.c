#include "./string.h"

static void assign_s(string_t *this, const string_t *str);
static void assign_c(string_t *this, const char *s);

static void assign_s(string_t *this, const string_t *str)
{
    free(this->str);
    this->str = strdup(str->str);
}

static void assign_c(string_t *this, const char *s)
{
    free(this->str);
    this->str = strdup(s);
}