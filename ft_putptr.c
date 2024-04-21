#include "ft_printf.h"

int ft_putptr(unsigned long n)
{
    char digit;
    int count;

    count = 0;

    write(1, "0x", 2);
    count += 2;
    if (n >= 16)
    {
        ft_puthex(n / 16, 0);
        ft_puthex(n % 16, 0);
        count++;
    }
    else
    {
        if (n < 10)
            digit = n + '0';
        else
            digit = (n - 10) + 'a';
        write(1,&digit,1);
        count++;
    }
    return(count);
}