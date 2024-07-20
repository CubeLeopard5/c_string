#include "include.h"
#include <criterion/criterion.h>

Test(substring_tests, substring_basic) {
    string_t s;
    string_init(&s, "hello world");
    string_t result = s.substring(&s, 0, 5);

    cr_assert_str_eq(result.str, "hello", "Expected substring to be 'hello'");

    string_destroy(&result);
    string_destroy(&s);
}

Test(substring_tests, substring_middle) {
    string_t s;
    string_init(&s, "hello world");
    string_t result = s.substring(&s, 6, 5);

    cr_assert_str_eq(result.str, "world", "Expected substring to be 'world'");

    string_destroy(&result);
    string_destroy(&s);
}

Test(substring_tests, substring_entire_string) {
    string_t s;
    string_init(&s, "hello world");
    string_t result = s.substring(&s, 0, 11);

    cr_assert_str_eq(result.str, "hello world", "Expected substring to be 'hello world'");

    string_destroy(&result);
    string_destroy(&s);
}

Test(substring_tests, substring_past_end) {
    string_t s;
    string_init(&s, "hello");
    string_t result = s.substring(&s, 3, 10);

    cr_assert_str_eq(result.str, "lo", "Expected substring to be 'lo'");

    string_destroy(&result);
    string_destroy(&s);
}

Test(substring_tests, substring_start_past_end) {
    string_t s;
    string_init(&s, "hello");
    string_t result = s.substring(&s, 10, 2);

    cr_assert_str_eq(result.str, "", "Expected substring to be an empty string when start is past the end");

    string_destroy(&result);
    string_destroy(&s);
}

Test(substring_tests, substring_empty_string) {
    string_t s;
    string_init(&s, "");
    string_t result = s.substring(&s, 0, 2);

    cr_assert_str_eq(result.str, "", "Expected substring to be an empty string when input string is empty");

    string_destroy(&result);
    string_destroy(&s);
}

Test(substring_tests, substring_zero_length) {
    string_t s;
    string_init(&s, "hello world");
    string_t result = s.substring(&s, 0, 0);

    cr_assert_str_eq(result.str, "", "Expected substring to be an empty string when length is zero");

    string_destroy(&result);
    string_destroy(&s);
}

Test(substring_tests, substring_start_at_end) {
    string_t s;
    string_init(&s, "hello");
    string_t result = s.substring(&s, 5, 2);

    cr_assert_str_eq(result.str, "", "Expected substring to be an empty string when start is at the end");

    string_destroy(&result);
    string_destroy(&s);
}

Test(substring_tests, substring_special_characters) {
    string_t s;
    string_init(&s, "!@#$%^&*()_+");
    string_t result = s.substring(&s, 2, 5);

    cr_assert_str_eq(result.str, "#$%^&", "Expected substring to be '#$%^&'");

    string_destroy(&result);
    string_destroy(&s);
}