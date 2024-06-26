#include "include.h"

static string_t *assign_s(string_t *this, const string_t *str);
static string_t *assign_c(string_t *this, const char *s);

/*
    Replace the content of this struct by the content of another string_t struct
*/
static string_t *assign_s(string_t *this, const string_t *str)
{
    free(this->str);
    this->str = strdup(str->str);
    return this;
}

static string_t *assign_c(string_t *this, const char *s)
{
    free(this->str);
    this->str = strdup(s);
    return this;
}