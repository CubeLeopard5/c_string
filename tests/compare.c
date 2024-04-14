#include "include.h"
#include <criterion/criterion.h>

Test(compare_s, compares_strings) {
    string_t str1;
    string_t str2;
    string_init(&str1, "Hello");
    string_init(&str2, "Hello");

    int result = str1.compare_s(&str1, &str2);

    cr_assert_eq(result, 0);

    string_destroy(&str1);
    string_destroy(&str2);
}

Test(compare_s, handles_different_strings) {
    string_t str1;
    string_t str2;
    string_init(&str1, "Hello");
    string_init(&str2, "World");

    int result = str1.compare_s(&str1, &str2);

    cr_assert_lt(result, 0);

    string_destroy(&str1);
    string_destroy(&str2);
}

Test(compare_c, compares_string_with_literal) {
    string_t str;
    string_init(&str, "Hello");

    int result = str.compare_c(&str, "Hello");

    cr_assert_eq(result, 0);

    string_destroy(&str);
}

Test(compare_c, handles_different_strings) {
    string_t str;
    string_init(&str, "Hello");

    int result = str.compare_c(&str, "World");

    cr_assert_lt(result, 0);

    string_destroy(&str);
}
