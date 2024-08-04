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
#include "starts_with.c"
#include "ends_with.c"
#include "to_lower.c"
#include "to_upper.c"
#include "trim.c"
#include "substring.c"
#include "reverse.c"
#include "replace.c"
#include "split.c"
#include "select.c"

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
    this->copy_c = &copy_c;
    this->copy_s = &copy_s;
    this->is_empty = &is_empty;
    this->c_str = &c_str;
    this->find_c = &find_c;
    this->find_s = &find_s;
    this->insert_c = &insert_c;
    this->insert_s = &insert_s;
    this->to_int = &to_int;
    this->starts_with = &starts_with;
    this->ends_with = &ends_with;
    this->to_lower = &to_lower;
    this->to_upper = &to_upper;
    this->trim = &trim;
    this->select_s = &select_s;
    this->substring = &substring;
    this->reverse = &reverse;
    this->replace = &replace;
    this->split = &split;
}

void string_init(string_t *this, const char *s)
{
    if (s)
        this->str = strdup(s);
    else
        this->str = NULL;
    init_struct(this);
}