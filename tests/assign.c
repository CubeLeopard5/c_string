#include "include.h"
#include <criterion/criterion.h>

Test(assign_s, assign_string_to_string) {
    string_t str1;
    string_t str2;
    string_init(&str1, "Hello");
    string_init(&str2, "World");

    str1.assign_s(&str1, &str2);

    cr_assert_str_eq(str1.str, "World");

    string_destroy(&str1);
    string_destroy(&str2);
}

Test(assign_s, original_string_preserved) {
    string_t str1;
    string_t str2;
    string_init(&str1, "Hello");
    string_init(&str2, "World");

    str1.assign_s(&str1, &str2);

    cr_assert_str_eq(str2.str, "World");

    string_destroy(&str1);
    string_destroy(&str2);
}

Test(assign_c, assign_string_literal_to_string) {
    string_t str1;
    string_init(&str1, "Hello");

    str1.assign_c(&str1, "World");

    cr_assert_str_eq(str1.str, "World");

    string_destroy(&str1);
}

Test(assign_c, original_string_preserved) {
    string_t str1;
    string_init(&str1, "Hello");
    char original_str[100];
    strcpy(original_str, str1.str);

    str1.assign_c(&str1, "World");

    cr_assert_str_eq(str1.str, "World");

    string_destroy(&str1);
}

Test(assign_c, handles_empty_string) {
    string_t str1;
    string_init(&str1, "");

    str1.assign_c(&str1, "World");

    cr_assert_str_eq(str1.str, "World");

    string_destroy(&str1);
}
