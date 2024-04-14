#include "include.h"

static char at(const string_t *this, size_t pos);

static char at(const string_t *this, size_t pos)
{
    if ((this && pos > strlen(this->str)) || pos == 0)
        return -1;
    return this->str[pos];
}