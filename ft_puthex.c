#include "ft_printf.h"

int ft_puthex(unsigned long long n , int upper)
{
    char digit;
    int count;

    count = 0;

    if (n >= 16)
    {
        ft_puthex(n / 16, upper);
        ft_puthex(n % 16, upper);
        count++;
    }
    else if (upper == 0)
    {
        if (n < 10)
            digit = n + '0';
        else
            digit = (n - 10) + 'a';
        write(1,&digit,1);
        count++;
    }
    else if (upper == 1)
    {
        if (n < 10)
            digit = n + '0';
        else
            digit = (n - 10) + 'A';
        write(1,&digit,1);
        count++;
    }
    return(count);
}