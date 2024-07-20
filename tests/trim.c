#include "include.h"
#include <criterion/criterion.h>

Test(trim_tests, trim_basic) {
    string_t s;
    string_init(&s, "   hello world   ");
    s.trim(&s);

    cr_assert_str_eq(s.str, "hello world", "Expected trimmed string to be 'hello world'");

    string_destroy(&s);
}

Test(trim_tests, trim_no_whitespace) {
    string_t s;
    string_init(&s, "hello");
    s.trim(&s);

    cr_assert_str_eq(s.str, "hello", "Expected trimmed string to be 'hello'");

    string_destroy(&s);
}

Test(trim_tests, trim_only_whitespace) {
    string_t s;
    string_init(&s, "     ");
    s.trim(&s);

    cr_assert_str_eq(s.str, "", "Expected trimmed string to be an empty string");

    string_destroy(&s);
}

Test(trim_tests, trim_leading_whitespace) {
    string_t s;
    string_init(&s, "   leading");
    s.trim(&s);

    cr_assert_str_eq(s.str, "leading", "Expected trimmed string to be 'leading'");

    string_destroy(&s);
}

Test(trim_tests, trim_trailing_whitespace) {
    string_t s;
    string_init(&s, "trailing   ");
    s.trim(&s);

    cr_assert_str_eq(s.str, "trailing", "Expected trimmed string to be 'trailing'");

    string_destroy(&s);
}

Test(trim_tests, trim_leading_and_trailing_whitespace) {
    string_t s;
    string_init(&s, "   leading and trailing   ");
    s.trim(&s);

    cr_assert_str_eq(s.str, "leading and trailing", "Expected trimmed string to be 'leading and trailing'");

    string_destroy(&s);
}

Test(trim_tests, trim_empty_string) {
    string_t s;
    string_init(&s, "");
    s.trim(&s);

    cr_assert_str_eq(s.str, "", "Expected trimmed string to be an empty string");

    string_destroy(&s);
}

Test(trim_tests, trim_whitespace_only) {
    string_t s;
    string_init(&s, "\t\n \v\f\r");
    s.trim(&s);

    cr_assert_str_eq(s.str, "", "Expected trimmed string to be an empty string for whitespace only");

    string_destroy(&s);
}

Test(trim_tests, trim_multiple_spaces) {
    string_t s;
    string_init(&s, "   multiple   spaces   ");
    s.trim(&s);

    cr_assert_str_eq(s.str, "multiple   spaces", "Expected trimmed string to be 'multiple   spaces'");

    string_destroy(&s);
}