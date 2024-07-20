#include "include.h"
#include <criterion/criterion.h>

// Helper function to free the array of string_t structures returned by split
void split_destroy(string_t *result, size_t count) {
    for (size_t i = 0; i < count; ++i) {
        free(result[i].str);
    }
    free(result);
}

// Test cases for the split function
Test(split_tests, split_basic) {
    string_t s;
    string_init(&s, "hello,world,test");
    size_t count;
    string_t *result = s.split(&s, ',', &count);

    cr_assert_eq(count, 3, "Expected 3 segments");
    cr_assert_str_eq(result[0].str, "hello", "Expected first segment to be 'hello'");
    cr_assert_str_eq(result[1].str, "world", "Expected second segment to be 'world'");
    cr_assert_str_eq(result[2].str, "test", "Expected third segment to be 'test'");

    split_destroy(result, count);
    string_destroy(&s);
}

Test(split_tests, split_single_segment) {
    string_t s;
    string_init(&s, "hello");
    size_t count;
    string_t *result = s.split(&s, ',', &count);

    cr_assert_eq(count, 1, "Expected 1 segment");
    cr_assert_str_eq(result[0].str, "hello", "Expected only segment to be 'hello'");

    split_destroy(result, count);
    string_destroy(&s);
}

Test(split_tests, split_no_segments) {
    string_t s;
    string_init(&s, "");
    size_t count;
    string_t *result = s.split(&s, ',', &count);

    cr_assert_eq(count, 1, "Expected 1 segment for an empty string");
    cr_assert_str_eq(result[0].str, "", "Expected only segment to be an empty string");

    split_destroy(result, count);
    string_destroy(&s);
}

Test(split_tests, split_only_delimiters) {
    string_t s;
    string_init(&s, ",,,");
    size_t count;
    string_t *result = s.split(&s, ',', &count);

    cr_assert_eq(count, 4, "Expected 4 segments");
    cr_assert_str_eq(result[0].str, "", "Expected first segment to be an empty string");
    cr_assert_str_eq(result[1].str, "", "Expected second segment to be an empty string");
    cr_assert_str_eq(result[2].str, "", "Expected third segment to be an empty string");
    cr_assert_str_eq(result[3].str, "", "Expected fourth segment to be an empty string");

    split_destroy(result, count);
    string_destroy(&s);
}

Test(split_tests, split_with_spaces) {
    string_t s;
    string_init(&s, "hello world test");
    size_t count;
    string_t *result = s.split(&s, ' ', &count);

    cr_assert_eq(count, 3, "Expected 3 segments");
    cr_assert_str_eq(result[0].str, "hello", "Expected first segment to be 'hello'");
    cr_assert_str_eq(result[1].str, "world", "Expected second segment to be 'world'");
    cr_assert_str_eq(result[2].str, "test", "Expected third segment to be 'test'");

    split_destroy(result, count);
    string_destroy(&s);
}

Test(split_tests, split_with_numbers) {
    string_t s;
    string_init(&s, "123,456,789");
    size_t count;
    string_t *result = s.split(&s, ',', &count);

    cr_assert_eq(count, 3, "Expected 3 segments");
    cr_assert_str_eq(result[0].str, "123", "Expected first segment to be '123'");
    cr_assert_str_eq(result[1].str, "456", "Expected second segment to be '456'");
    cr_assert_str_eq(result[2].str, "789", "Expected third segment to be '789'");

    split_destroy(result, count);
    string_destroy(&s);
}

Test(split_tests, split_special_characters) {
    string_t s;
    string_init(&s, "!@#$%^&");
    size_t count;
    string_t *result = s.split(&s, '#', &count);

    cr_assert_eq(count, 2, "Expected 2 segments");
    cr_assert_str_eq(result[0].str, "!@", "Expected first segment to be '!@'");
    cr_assert_str_eq(result[1].str, "$%^&", "Expected second segment to be '$%^&'");

    split_destroy(result, count);
    string_destroy(&s);
}

Test(split_tests, split_long_string) {
    string_t s;
    string_init(&s, "a quick brown fox jumps over the lazy dog");
    size_t count;
    string_t *result = s.split(&s, ' ', &count);

    cr_assert_eq(count, 9, "Expected 9 segments");
    cr_assert_str_eq(result[0].str, "a", "Expected first segment to be 'a'");
    cr_assert_str_eq(result[1].str, "quick", "Expected second segment to be 'quick'");
    cr_assert_str_eq(result[2].str, "brown", "Expected third segment to be 'brown'");
    cr_assert_str_eq(result[3].str, "fox", "Expected fourth segment to be 'fox'");
    cr_assert_str_eq(result[4].str, "jumps", "Expected fifth segment to be 'jumps'");
    cr_assert_str_eq(result[5].str, "over", "Expected sixth segment to be 'over'");
    cr_assert_str_eq(result[6].str, "the", "Expected seventh segment to be 'the'");
    cr_assert_str_eq(result[7].str, "lazy", "Expected eighth segment to be 'lazy'");
    cr_assert_str_eq(result[8].str, "dog", "Expected ninth segment to be 'dog'");

    split_destroy(result, count);
    string_destroy(&s);
}