#include "include.h"
#include <criterion/criterion.h>

Test(reverse_tests, reverse_non_empty_string) {
    string_t s;
    string_init(&s, "hello");
    s.reverse(&s);
    cr_assert_str_eq(s.str, "olleh", "Expected 'hello' to become 'olleh'");
    string_destroy(&s);
}

Test(reverse_tests, reverse_palindrome_string) {
    string_t s;
    string_init(&s, "madam");
    s.reverse(&s);
    cr_assert_str_eq(s.str, "madam", "Expected 'madam' to remain 'madam'");
    string_destroy(&s);
}

Test(reverse_tests, reverse_single_character_string) {
    string_t s;
    string_init(&s, "a");
    s.reverse(&s);
    cr_assert_str_eq(s.str, "a", "Expected 'a' to remain 'a'");
    string_destroy(&s);
}

Test(reverse_tests, reverse_empty_string) {
    string_t s;
    string_init(&s, "");
    s.reverse(&s);
    cr_assert_str_eq(s.str, "", "Expected empty string to remain empty");
    string_destroy(&s);
}

Test(reverse_tests, reverse_string_with_spaces) {
    string_t s;
    string_init(&s, "hello world");
    s.reverse(&s);
    cr_assert_str_eq(s.str, "dlrow olleh", "Expected 'hello world' to become 'dlrow olleh'");
    string_destroy(&s);
}

Test(reverse_tests, reverse_string_with_numbers) {
    string_t s;
    string_init(&s, "12345");
    s.reverse(&s);
    cr_assert_str_eq(s.str, "54321", "Expected '12345' to become '54321'");
    string_destroy(&s);
}

Test(reverse_tests, reverse_string_with_special_characters) {
    string_t s;
    string_init(&s, "!@#$%");
    s.reverse(&s);
    cr_assert_str_eq(s.str, "%$#@!", "Expected '!@#$%' to become '%$#@!'");
    string_destroy(&s);
}

Test(reverse_tests, reverse_long_string) {
    string_t s;
    string_init(&s, "a quick brown fox jumps over the lazy dog");
    s.reverse(&s);
    cr_assert_str_eq(s.str, "god yzal eht revo spmuj xof nworb kciuq a", "Expected 'a quick brown fox jumps over the lazy dog' to become 'god yzal eht revo spmuj xof nworb kciuq a'");
    string_destroy(&s);
}