#include "include.h"

int main(void)
{
    string_t s;

    string_init(&s, "asbcdefghsijklmnopqrstuvwxyzs");

    string_t t = s.select_s(&s, 's');
    printf("%s", t.str);

    string_destroy(&s);

    return 0;
}