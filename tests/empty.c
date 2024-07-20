#include "include.h"
#include <criterion/criterion.h>

Test(empty, returns_true_for_empty_string) {
    string_t str;
    string_init(&str, "");

    int result = str.is_empty(&str);

    cr_assert_eq(result, 1);

    string_destroy(&str);
}

Test(empty, returns_false_for_non_empty_string) {
    string_t str;
    string_init(&str, "Hello");

    int result = str.is_empty(&str);

    cr_assert_eq(result, 0);

    string_destroy(&str);
}