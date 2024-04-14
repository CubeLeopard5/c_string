#include "include.h"

static const char *c_str(const string_t *this);

static const char *c_str(const string_t *this)
{
    return (this->str);
}