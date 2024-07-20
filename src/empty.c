#include "include.h"

static int is_empty(const string_t *this);

static int is_empty(const string_t *this)
{
    if (!this || !this->str)
        return 1;
    if (strlen(this->str) == 0)
        return 1;
    return 0;
}