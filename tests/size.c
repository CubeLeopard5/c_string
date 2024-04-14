#include "include.h"
#include <criterion/criterion.h>

Test(size, returns_size_of_string) {
    string_t str;
    string_init(&str, "Hello");

    int result = str.size(&str);

    cr_assert_eq(result, 5);

    string_destroy(&str);
}

Test(size, handles_empty_string) {
    string_t str;
    string_init(&str, "");

    int result = str.size(&str);

    cr_assert_eq(result, 0);

    string_destroy(&str);
}
