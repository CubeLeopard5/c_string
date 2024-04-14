#include "include.h"
#include <criterion/criterion.h>

Test(find_s, finds_substring_within_string) {
    string_t str;
    string_init(&str, "Hello World");

    string_t substr;
    string_init(&substr, "World");

    int result = str.find_s(&str, &substr, 0);

    cr_assert_eq(result, 6);

    string_destroy(&str);
    string_destroy(&substr);
}

Test(find_s, finds_substring_within_string_with_start_position) {
    string_t str;
    string_init(&str, "Hello World World");

    string_t substr;
    string_init(&substr, "World");

    int result = str.find_s(&str, &substr, 7);

    cr_assert_eq(result, 12);

    string_destroy(&str);
    string_destroy(&substr);
}

Test(find_s, returns_negative_one_if_substring_not_found) {
    string_t str;
    string_init(&str, "Hello World");

    string_t substr;
    string_init(&substr, "Universe");

    int result = str.find_s(&str, &substr, 0);

    cr_assert_eq(result, -1);

    string_destroy(&str);
    string_destroy(&substr);
}

Test(find_c, finds_substring_within_string) {
    string_t str;
    string_init(&str, "Hello World");

    const char *substr = "World";

    int result = str.find_c(&str, substr, 0);

    cr_assert_eq(result, 6);

    string_destroy(&str);
}

Test(find_c, finds_substring_within_string_with_start_position) {
    string_t str;
    string_init(&str, "Hello World World");

    const char *substr = "World";

    int result = str.find_c(&str, substr, 7);

    cr_assert_eq(result, 12);

    string_destroy(&str);
}

Test(find_c, returns_negative_one_if_substring_not_found) {
    string_t str;
    string_init(&str, "Hello World");

    const char *substr = "Universe";

    int result = str.find_c(&str, substr, 0);

    cr_assert_eq(result, -1);

    string_destroy(&str);
}
