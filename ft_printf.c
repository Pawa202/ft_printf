#include "ft_printf.h"
static int ft_parse_format(char c, va_list args)
{
    int count;
    
    count = 0;
    if (c == 'c')
        count += ft_putchar(va_arg(args, int));
    else if (c == 's')
        count += ft_putstr(va_arg(args,char *));
    else if (c == 'd' || c == 'i')
        count += ft_putnbr(va_arg(args, int));
    else if (c == 'u')
        count += ft_putunbr(va_arg(args,unsigned int));
    else if (c == 'x')
        count += ft_puthex(va_arg(args, unsigned int), 0);
    else if (c == 'X')
        count +=ft_puthex(va_arg(args, unsigned int), 1);
    else if (c == 'p')
        count += ft_putptr(va_arg(args, unsigned long));
    else if (c == '%')
    {
        write(1, "%", 1);
        count++;
    }

    return(count);
}
int    ft_printf(const char *format, ...)
{
    va_list	args;
    int        count;

    va_start(args, format);
    count = 0;
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            count += ft_parse_format(*format, args);
            
        }
        else
        {
            write(1, format, 1);
            count++;
        }
        format++;
        va_end(args);
    }
    return(count);
}


int main() {
    char *name = "John";
    int age = 30;

    ft_printf("Hello, my name is %s and I am %d years old.\n", name, age);

    return 0;
}