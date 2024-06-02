#include "include.h"

static string_t *append_s(string_t *this, const string_t *ap);
static string_t *append_c(string_t *this, const char *ap);

/*
    Append a string ap at the end of this struct
    ap must be another string_t struct
*/
static string_t *append_s(string_t *this, const string_t *ap)
{
    char *str =
    malloc(sizeof(char) * (strlen(this->str) + strlen(ap->str) + 1));

    str = strcpy(str, this->str);
    free(this->str);
    str = strcat(str, ap->str);
    this->str = strdup(str);
    free(str);
    return this;
}

/*
    Append a string ap at the end of this struct
    ap must be a char *
*/
static string_t *append_c(string_t *this, const char *ap)
{
    char *str =
    malloc(sizeof(char) * (strlen(this->str) + strlen(ap) + 1));

    str = strcpy(str, this->str);
    free(this->str);
    str = strcat(str, ap);
    this->str = strdup(str);
    free(str);
    return this;
}