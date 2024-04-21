#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int    ft_printf(const char *format, ...);
int ft_putchar(int c);
int ft_putstr(char *str);
int ft_putnbr(int n);
int ft_putunbr(unsigned int n);
int ft_puthex(unsigned long long n , int upper);
int ft_putptr(unsigned long n);


#endif