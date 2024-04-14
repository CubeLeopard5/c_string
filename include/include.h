/*
** EPITECH PROJECT, 2021
** sdfghj
** File description:
** kjhgfd
*/

#ifndef STRING_H
#define STRING_H

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct string_s
{
    char *str;

    struct string_s *(*assign_s)(struct string_s *this, const struct string_s *str);
    struct string_s *(*assign_c)(struct string_s *this, const char *s);
    struct string_s *(*append_s)(struct string_s *this, const struct string_s *ap);
    struct string_s *(*append_c)(struct string_s *this, const char *ap);
    char (*at)(const struct string_s *this, size_t pos);
    struct string_s *(*clear)(struct string_s *this);
    int (*size)(const struct string_s *this);
    int (*compare_s)(const struct string_s *this, const struct string_s *str);
    int (*compare_c)(const struct string_s *this, const char *str);
    size_t (*copy)(const struct string_s *this, char *s, size_t n, size_t pos);
    const char *(*c_str)(const struct string_s *this);
    int (*empty)(const struct string_s *this);
    int (*find_s)(const struct string_s *this,
    const struct string_s *str, size_t pos);
    int (*find_c)(const struct string_s *this, const char *str, size_t pos);
    struct string_s *(*insert_c)(struct string_s *this, size_t pos, const char *str);
    struct string_s *(*insert_s)(struct string_s *this,
    size_t pos, const struct string_s *str);
    int (*to_int)(const struct string_s *this);
} string_t;

void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);

#endif