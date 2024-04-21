#include "ft_printf.h"

int ft_putnbr(int n)
{
    char digit;
    int count;

    count = 0;

    if ( n == -2147483648)
    {
        write(1, "-2147483648", 11);

    }
    else if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
        ft_putnbr(n);
    }
    else
    {
        if(n >= 10)
        {
            ft_putnbr(n / 10);
            ft_putnbr(n % 10);
            count++;
        }
        else
        {
            digit = n + '0';
            write(1, &digit, 1);
            count++;
        }
    }
    return(count);
}