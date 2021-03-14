#include "rush.h"

void    initialize(void *pointer, int size)
{
    int i;
    i = -1;
    while (++i < size)
        *((char *)pointer + i) = 0;
}

void ft_putchar(char *str)
{
    int i;
    i = -1;
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
}

void ft_putchar_space(char *str)
{
    ft_putchar(str);
    write(1, " ", 1);
}

size_t ft_strlen(char *str)
{
    size_t str_len;
    str_len = 0;
    while(str[str_len])
        str_len++;
    return str_len;
}