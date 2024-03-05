#include <stdint.h>
#include <stdio.h>

int main()
{
    char str[26];
    for (size_t i = 0; i < sizeof(str); i++)
    {
        str[i] = 'A' + i;
        putch(str[i]);
    }
    putch('\n');
    return 0;
}