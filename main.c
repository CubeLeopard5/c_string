#include "include.h"

int main(void)
{
    string_t s;

    string_init(&s, "abcdefghijklmnopqrstuvwxyz");

    s.replace(&s, "a", "z");
    printf("%s", s.str);

    string_destroy(&s);

    return 0;
}