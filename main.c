#include "include.h"

int main(void)
{
    string_t s;

    string_init(&s, "abcdefghijklmnopqrstuvwxyz");

    printf("%d\n", s.find_c(&s, "mno", 20));

    string_destroy(&s);

    return 0;
}