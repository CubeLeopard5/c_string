#include "include.h"
#include <criterion/criterion.h>

Test(append_s, append_string_to_string) {
    string_t str1;
    string_t str2;
    string_init(&str1, "Hello");
    string_init(&str2, " World!");

    str1.append_s(&str1, &str2);

    cr_assert_str_eq(str1.str, "Hello World!");

    string_destroy(&str1);
    string_destroy(&str2);
}

Test(append_s, original_string_preserved) {
    string_t str1;
    string_t str2;
    string_init(&str1, "Hello");
    string_init(&str2, " World!");

    str1.append_s(&str1, &str2);

    cr_assert_str_eq(str2.str, " World!");

    string_destroy(&str1);
    string_destroy(&str2);
}

Test(append_s, handles_empty_string) {
    string_t str1;
    string_t str2;
    string_init(&str1, "");
    string_init(&str2, " World!");

    str1.append_s(&str1, &str2);

    cr_assert_str_eq(str1.str, " World!");

    string_destroy(&str1);
    string_destroy(&str2);
}

Test(append_c, append_string_literal_to_string) {
    string_t str1;
    string_init(&str1, "Hello");

    str1.append_c(&str1, " World!");

    cr_assert_str_eq(str1.str, "Hello World!");

    string_destroy(&str1);
}

Test(append_c, handles_empty_string) {
    string_t str1;
    string_init(&str1, "");

    str1.append_c(&str1, " World!");

    cr_assert_str_eq(str1.str, " World!");

    string_destroy(&str1);
}
