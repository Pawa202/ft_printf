#include "ft_printf.h"

int ft_putstr(char *str)
{
    int count;

    count = 0;
    while(*str)
    {
        write(1, str, 1);
        str++;
        count++;
    }
    return(count);
}