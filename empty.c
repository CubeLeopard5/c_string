#include "./string.h"

static int empty(const string_t *this);

int empty(const string_t *this)
{
    if (!this || !this->str)
        return 1;
    if (strlen(this->str) == 0)
        return 1;
    return 0;
}