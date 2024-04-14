/*
** EPITECH PROJECT, 2021
** dfghj
** File description:
** jhgf
*/

#include "include.h"
#include "copy.c"
#include "assign.c"
#include "append.c"
#include "compare.c"
#include "at.c"
#include "clear.c"
#include "size.c"
#include "c_str.c"
#include "empty.c"
#include "find.c"
#include "insert.c"
#include "to_int.c"

void init_struct(string_t *this)
{
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->at = &at;
    this->clear = &clear;
    this->size = &size;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
    this->empty = &empty;
    this->c_str = &c_str;
    this->find_c = &find_c;
    this->find_s = &find_s;
    this->insert_c = &insert_c;
    this->insert_s = &insert_s;
    this->to_int = &to_int;
}

void string_init(string_t *this, const char *s)
{
    if (s)
        this->str = strdup(s);
    else
        this->str = NULL;
    init_struct(this);
}