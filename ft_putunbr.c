#include "ft_printf.h"
int ft_putunbr(unsigned int n)
{
    char digit;
    int count;

    count = 0;

    if (n >= 10)
    {
        ft_putunbr(n / 10);
        ft_putunbr(n % 10);
        count++;
    }
    else
    {
        digit = n + '0';
        write(1, &digit, 1);
        count++;
    }
    return(count);
}

