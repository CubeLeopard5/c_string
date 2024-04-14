#include "include.h"
#include <criterion/criterion.h>

Test(at, returns_character_at_position) {
    string_t str;
    string_init(&str, "Hello");

    char result = str.at(&str, 2);

    cr_assert_eq(result, 'l');

    string_destroy(&str);
}

Test(at, returns_negative_one_for_out_of_range_position) {
    string_t str;
    string_init(&str, "Hello");

    char result = str.at(&str, 10);

    cr_assert_eq(result, -1);

    string_destroy(&str);
}

Test(at, handles_empty_string) {
    string_t str;
    string_init(&str, "");

    char result = str.at(&str, 0);

    cr_assert_eq(result, -1);

    string_destroy(&str);
}
