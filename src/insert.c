#include "include.h"

static string_t *insert_c(string_t *this, size_t pos, const char *str);
static string_t *insert_s(string_t *this, size_t pos, const string_t *str);

static string_t *insert_c(string_t *this, size_t pos, const char *str)
{
    char *str2;

    str2 = malloc(sizeof(char) * (strlen(this->str) + strlen(str)) + 1);
    if (pos > strlen(this->str))
        pos = strlen(this->str);
    strncpy(str2, this->str, pos);
    str2[pos] = '\0';
    strcat(str2, str);
    strcat(str2, this->str + pos);
    free(this->str);
    this->str = strdup(str2);
    free(str2);
    return this;
}

static string_t *insert_s(string_t *this, size_t pos, const string_t *str)
{
    char *str2;

    str2 = malloc(sizeof(char) * (strlen(this->str) + strlen(str->str)) + 1);
    if (pos > strlen(this->str))
        pos = strlen(this->str);
    strncpy(str2, this->str, pos);
    str2[pos] = '\0';
    strcat(str2, str->str);
    strcat(str2, this->str + pos);
    free(this->str);
    this->str = strdup(str2);
    free(str2);
    return this;
}