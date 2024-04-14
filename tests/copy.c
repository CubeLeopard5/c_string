#include "include.h"
#include <criterion/criterion.h>

Test(copy, copies_string_to_buffer) {
    string_t str;
    string_init(&str, "Hello");

    char buffer[10];
    size_t result = str.copy(&str, buffer, 5, 0);

    cr_assert_str_eq(buffer, "Hello");
    cr_assert_eq(result, 5);

    string_destroy(&str);
}

Test(copy, handles_start_position) {
    string_t str;
    string_init(&str, "Hello");

    char buffer[10];
    size_t result = str.copy(&str, buffer, 3, 2);

    cr_assert_str_eq(buffer, "llo");
    cr_assert_eq(result, 3);

    string_destroy(&str);
}

Test(copy, handles_exceeding_buffer_size) {
    string_t str;
    string_init(&str, "Hello");

    char buffer[10];
    size_t result = str.copy(&str, buffer, 10, 0);

    cr_assert_str_eq(buffer, "Hello");
    cr_assert_eq(result, 5);

    string_destroy(&str);
}

Test(copy, returns_actual_length_copied) {
    string_t str;
    string_init(&str, "Hello");

    char buffer[10];
    size_t result = str.copy(&str, buffer, 5, 3);

    cr_assert_str_eq(buffer, "lo");
    cr_assert_eq(result, 2);

    string_destroy(&str);
}

Test(copy, handles_empty_string) {
    string_t str;
    string_init(&str, "");

    char buffer[10];
    size_t result = str.copy(&str, buffer, 5, 0);

    cr_assert_str_empty(buffer);
    cr_assert_eq(result, 0);

    string_destroy(&str);
}
