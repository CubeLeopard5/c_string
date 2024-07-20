#include "include.h"
#include <criterion/criterion.h>

Test(starts_with_tests, starts_with_basic) {
    string_t s;
    string_init(&s, "hello world");
    int result = s.starts_with(&s, "hello");
    cr_assert(result, "Expected 'hello world' to start with 'hello'");
    string_destroy(&s);
}

Test(starts_with_tests, starts_with_full_match) {
    string_t s;
    string_init(&s, "hello");
    int result = s.starts_with(&s, "hello");
    cr_assert(result, "Expected 'hello' to start with 'hello'");
    string_destroy(&s);
}

Test(starts_with_tests, starts_with_prefix_longer_than_string) {
    string_t s;
    string_init(&s, "hi");
    int result = s.starts_with(&s, "hello");
    cr_assert_not(result, "Expected 'hi' not to start with 'hello'");
    string_destroy(&s);
}

Test(starts_with_tests, starts_with_empty_prefix) {
    string_t s;
    string_init(&s, "hello");
    int result = s.starts_with(&s, "");
    cr_assert(result, "Expected 'hello' to start with an empty prefix");
    string_destroy(&s);
}

Test(starts_with_tests, starts_with_empty_string_and_empty_prefix) {
    string_t s;
    string_init(&s, "");
    int result = s.starts_with(&s, "");
    cr_assert(result, "Expected empty string to start with an empty prefix");
    string_destroy(&s);
}

Test(starts_with_tests, starts_with_different_case) {
    string_t s;
    string_init(&s, "Hello World");
    int result = s.starts_with(&s, "hello");
    cr_assert_not(result, "Expected 'Hello World' not to start with 'hello' (case-sensitive)");
    string_destroy(&s);
}

Test(starts_with_tests, starts_with_special_characters) {
    string_t s;
    string_init(&s, "!@#$%^&*()");
    int result = s.starts_with(&s, "!@#");
    cr_assert(result, "Expected '!@#$%^&*()' to start with '!@#'");
    string_destroy(&s);
}

Test(starts_with_tests, starts_with_long_prefix) {
    string_t s;
    string_init(&s, "a quick brown fox");
    int result = s.starts_with(&s, "a quick brown fox jumps over the lazy dog");
    cr_assert_not(result, "Expected 'a quick brown fox' not to start with 'a quick brown fox jumps over the lazy dog'");
    string_destroy(&s);
}

Test(starts_with_tests, starts_with_whitespace) {
    string_t s;
    string_init(&s, "    leading whitespace");
    int result = s.starts_with(&s, "    ");
    cr_assert(result, "Expected '    leading whitespace' to start with four spaces");
    string_destroy(&s);
}