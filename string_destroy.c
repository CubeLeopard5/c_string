/*
** EPITECH PROJECT, 2021
** dfghj
** File description:
** jhgfd
*/

#include "./string.h"

void string_destroy(string_t *this)
{
    if (this->str != NULL)
        free(this->str);
}