#include <stddef.h>

void bzero(void *s, size_t n)
{
    size_t i;
    char *ptr;

    i = 0;
    ptr = s;
    while (i < n)
    {
        ptr[i] = 0;
        i++;
    }
}