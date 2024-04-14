#include "include.h"
#include <criterion/criterion.h>

Test(c_str, returns_pointer_to_string) {
    string_t str;
    string_init(&str, "Hello");

    const char *result = str.c_str(&str);

    cr_assert_str_eq(result, "Hello");

    string_destroy(&str);
}

Test(c_str, returns_correct_pointer_after_modification) {
    string_t str;
    string_init(&str, "Hello");

    str.str[1] = 'i'; // Modify the string

    const char *result = str.c_str(&str);

    cr_assert_str_eq(result, "Hillo");

    string_destroy(&str);
}

Test(c_str, handles_empty_string) {
    string_t str;
    string_init(&str, "");

    const char *result = str.c_str(&str);

    cr_assert_str_empty(result);

    string_destroy(&str);
}
