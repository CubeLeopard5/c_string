#include "include.h"
#include <criterion/criterion.h>

Test(replace_tests, replace_single_occurrence) {
    string_t s;
    string_init(&s, "hello world");
    s.replace(&s, "world", "everyone");
    cr_assert_str_eq(s.str, "hello everyone", "Expected 'hello world' to become 'hello everyone'");
    string_destroy(&s);
}

Test(replace_tests, replace_multiple_occurrences) {
    string_t s;
    string_init(&s, "hello world world");
    s.replace(&s, "world", "everyone");
    cr_assert_str_eq(s.str, "hello everyone everyone", "Expected 'hello world world' to become 'hello everyone everyone'");
    string_destroy(&s);
}

Test(replace_tests, replace_no_occurrences) {
    string_t s;
    string_init(&s, "hello world");
    s.replace(&s, "earth", "everyone");
    cr_assert_str_eq(s.str, "hello world", "Expected 'hello world' to remain 'hello world'");
    string_destroy(&s);
}

Test(replace_tests, replace_empty_old_sub) {
    string_t s;
    string_init(&s, "hello world");
    s.replace(&s, "", "everyone");
    cr_assert_str_eq(s.str, "hello world", "Expected 'hello world' to remain 'hello world' when old substring is empty");
    string_destroy(&s);
}

Test(replace_tests, replace_with_empty_new_sub) {
    string_t s;
    string_init(&s, "hello world");
    s.replace(&s, "world", "");
    cr_assert_str_eq(s.str, "hello ", "Expected 'hello world' to become 'hello '");
    string_destroy(&s);
}

Test(replace_tests, replace_both_substrings_empty) {
    string_t s;
    string_init(&s, "hello world");
    s.replace(&s, "", "");
    cr_assert_str_eq(s.str, "hello world", "Expected 'hello world' to remain 'hello world' when both substrings are empty");
    string_destroy(&s);
}

Test(replace_tests, replace_old_sub_longer_than_new_sub) {
    string_t s;
    string_init(&s, "hello world");
    s.replace(&s, "world", "all");
    cr_assert_str_eq(s.str, "hello all", "Expected 'hello world' to become 'hello all'");
    string_destroy(&s);
}

Test(replace_tests, replace_new_sub_longer_than_old_sub) {
    string_t s;
    string_init(&s, "hello world");
    s.replace(&s, "world", "universe");
    cr_assert_str_eq(s.str, "hello universe", "Expected 'hello world' to become 'hello universe'");
    string_destroy(&s);
}

Test(replace_tests, replace_entire_string) {
    string_t s;
    string_init(&s, "world");
    s.replace(&s, "world", "everyone");
    cr_assert_str_eq(s.str, "everyone", "Expected 'world' to become 'everyone'");
    string_destroy(&s);
}

Test(replace_tests, replace_special_characters) {
    string_t s;
    string_init(&s, "hello, world!");
    s.replace(&s, "world", "everyone");
    cr_assert_str_eq(s.str, "hello, everyone!", "Expected 'hello, world!' to become 'hello, everyone!'");
    string_destroy(&s);
}

Test(replace_tests, replace_string_with_spaces) {
    string_t s;
    string_init(&s, "   ");
    s.replace(&s, " ", "_");
    cr_assert_str_eq(s.str, "___", "Expected '   ' to become '___'");
    string_destroy(&s);
}

Test(replace_tests, replace_substring_with_same_substring) {
    string_t s;
    string_init(&s, "hello world");
    s.replace(&s, "world", "world");
    cr_assert_str_eq(s.str, "hello world", "Expected 'hello world' to remain 'hello world'");
    string_destroy(&s);
}