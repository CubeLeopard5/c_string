#include "./string.h"

static void clear(string_t *this);

static void clear(string_t *this)
{
    free(this->str);
    this->str = '\0';
}