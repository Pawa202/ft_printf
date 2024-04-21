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


#include "ft_printf.h"

int main()
{
    char c = 'A';
    char *s = "Hello, World!";
    int d = -123;
    int i = 456;
    unsigned int u = 789;
    unsigned int x = 0xabc;
    unsigned int X = 0xDEF;
    unsigned long p = (unsigned long)&d;

    ft_printf("Testing ft_printf:\n");
    ft_printf("Character: %c\n", c);
    ft_printf("String: %s\n", s);
    ft_printf("Signed decimal integer: %d\n", d);
    ft_printf("Signed decimal integer: %i\n", i);
    ft_printf("Unsigned decimal integer: %u\n", u);
    ft_printf("Unsigned hexadecimal integer (lowercase): %x\n", x);
    ft_printf("Unsigned hexadecimal integer (uppercase): %X\n", X);
    ft_printf("Pointer: %p\n", (void *)p);
    ft_printf("Percent sign: %%\n");
    
    printf("Testing printf:\n");
    printf("Character: %c\n", c);
    printf("String: %s\n", s);
    printf("Signed decimal integer: %d\n", d);
    printf("Signed decimal integer: %i\n", i);
    printf("Unsigned decimal integer: %u\n", u);
    printf("Unsigned hexadecimal integer (lowercase): %x\n", x);
    printf("Unsigned hexadecimal integer (uppercase): %X\n", X);
    printf("Pointer: %p\n", (void *)p);
    printf("Percent sign: %%\n");

    return 0;
}