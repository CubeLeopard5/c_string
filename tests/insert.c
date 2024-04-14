#include "include.h"
#include <criterion/criterion.h>

Test(insert_c, inserts_string_at_position) {
    string_t str;
    string_init(&str, "Hello");

    str.insert_c(&str, 2, "World");

    cr_assert_str_eq(str.str, "HeWorldllo");

    string_destroy(&str);
}

Test(insert_c, handles_insertion_at_end_of_string) {
    string_t str;
    string_init(&str, "Hello");

    str.insert_c(&str, 5, " World");

    cr_assert_str_eq(str.str, "Hello World");

    string_destroy(&str);
}

Test(insert_c, handles_insertion_beyond_end_of_string) {
    string_t str;
    string_init(&str, "Hello");

    str.insert_c(&str, 10, " World");

    cr_assert_str_eq(str.str, "Hello World");

    string_destroy(&str);
}

Test(insert_s, inserts_string_at_position) {
    string_t str;
    string_init(&str, "Hello");

    string_t insert_str;
    string_init(&insert_str, "World");

    str.insert_s(&str, 2, &insert_str);

    cr_assert_str_eq(str.str, "HeWorldllo");

    string_destroy(&str);
    string_destroy(&insert_str);
}

Test(insert_s, handles_insertion_at_end_of_string) {
    string_t str;
    string_init(&str, "Hello");

    string_t insert_str;
    string_init(&insert_str, " World");

    str.insert_s(&str, 5, &insert_str);

    cr_assert_str_eq(str.str, "Hello World");

    string_destroy(&str);
    string_destroy(&insert_str);
}

Test(insert_s, handles_insertion_beyond_end_of_string) {
    string_t str;
    string_init(&str, "Hello");

    string_t insert_str;
    string_init(&insert_str, " World");

    str.insert_s(&str, 10, &insert_str);

    cr_assert_str_eq(str.str, "Hello World");

    string_destroy(&str);
    string_destroy(&insert_str);
}
