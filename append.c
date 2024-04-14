#include "./string.h"

static void append_s(string_t *this, const string_t *ap);
static void append_c(string_t *this, const char *ap);

static void append_s(string_t *this, const string_t *ap)
{
    char *str =
    malloc(sizeof(char) * (strlen(this->str) + strlen(ap->str) + 1));
    str = strcpy(str, this->str);
    free(this->str);
    str = strcat(str, ap->str);
    this->str = strdup(str);
    free(str);
}

static void append_c(string_t *this, const char *ap)
{
    char *str =
    malloc(sizeof(char) * (strlen(this->str) + strlen(ap) + 1));
    str = strcpy(str, this->str);
    free(this->str);
    str = strcat(str, ap);
    this->str = strdup(str);
    free(str);
}