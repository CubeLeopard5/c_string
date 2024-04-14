#include "include.h"

static string_t *clear(string_t *this);

static string_t *clear(string_t *this)
{
    free(this->str);
    this->str = '\0';
    return this;
}