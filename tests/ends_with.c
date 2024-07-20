#include "include.h"
#include <criterion/criterion.h>

Test(ends_with_tests, string_ends_with_suffix) {
    string_t s;
    string_init(&s, "hello world");

    cr_assert(s.ends_with(&s, "world") == 1, "Expected 'hello world' to end with 'world'");
}

Test(ends_with_tests, string_does_not_end_with_suffix) {
    string_t s;
    string_init(&s, "hello world");

    cr_assert(s.ends_with(&s, "hello") == 0, "Expected 'hello world' not to end with 'hello'");
}

Test(ends_with_tests, string_and_suffix_are_same) {
    string_t s;
    string_init(&s, "hello");

    cr_assert(s.ends_with(&s, "hello") == 1, "Expected 'hello' to end with 'hello'");
}

Test(ends_with_tests, suffix_is_empty) {
    string_t s;
    string_init(&s, "hello");

    cr_assert(s.ends_with(&s, "") == 1, "Expected 'hello' to end with an empty suffix");
}

Test(ends_with_tests, string_is_empty) {
    string_t s;
    string_init(&s, "");

    cr_assert(s.ends_with(&s, "hello") == 0, "Expected an empty string not to end with 'hello'");
}

Test(ends_with_tests, both_string_and_suffix_are_empty) {
    string_t s;
    string_init(&s, "");

    cr_assert(s.ends_with(&s, "") == 1, "Expected an empty string to end with an empty suffix");
}

Test(ends_with_tests, suffix_longer_than_string) {
    string_t s;
    string_init(&s, "hello");

    cr_assert(s.ends_with(&s, "hello world") == 0, "Expected 'hello' not to end with 'hello world'");
}

Test(ends_with_tests, null_string) {
    string_t s;
    string_init(&s, NULL);

    cr_assert(s.ends_with(&s, "hello") == 0, "Expected a null string not to end with 'hello'");
}

Test(ends_with_tests, string_ends_with_suffix_case_sensitive) {
    string_t s;
    string_init(&s, "Hello World");

    cr_assert(s.ends_with(&s, "world") == 0, "Expected 'Hello World' not to end with 'world' (case-sensitive check)");
    cr_assert(s.ends_with(&s, "World") == 1, "Expected 'Hello World' to end with 'World'");
}

Test(ends_with_tests, special_characters_in_suffix) {
    string_t s;
    string_init(&s, "hello world!");

    cr_assert(s.ends_with(&s, "world!") == 1, "Expected 'hello world!' to end with 'world!'");
    cr_assert(s.ends_with(&s, "world?") == 0, "Expected 'hello world!' not to end with 'world?'");
}

Test(ends_with_tests, string_with_spaces) {
    string_t s;
    string_init(&s, "   ");

    cr_assert(s.ends_with(&s, " ") == 1, "Expected '   ' to end with ' '");
    cr_assert(s.ends_with(&s, "   ") == 1, "Expected '   ' to end with '   '");
    cr_assert(s.ends_with(&s, "    ") == 0, "Expected '   ' not to end with '    '");
}