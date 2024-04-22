/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:58:57 by prutkows          #+#    #+#             */
/*   Updated: 2024/04/19 17:58:58 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 1;
	if (n == -2147483648)
	{
		ft_putchar('-');
		count += ft_putunbr(214748364);
		ft_putchar('8');
	}
	else if (n < 0)
	{
		ft_putchar('-');
		count += ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
	return (count);
}
