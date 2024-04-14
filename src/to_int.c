#include "include.h"

static int to_int(const string_t *this);

int to_int(const string_t *this)
{
    return atoi(this->str);
}