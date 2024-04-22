/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:41:59 by prutkows          #+#    #+#             */
/*   Updated: 2024/04/22 13:42:00 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putptr(unsigned long n)
{
	char	digit;
	int		count;

	count = 1;
	write(1, "0x", 2);
	count += 2;
	if (n >= 16)
	{
		count += ft_puthex_lower(n / 16);
		ft_puthex_lower(n % 16);
	}
	else
	{
		if (n < 10)
		{
			digit = n + '0';
		}
		else
			digit = (n - 10) + 'a';
		write(1, &digit, 1);
		count++;
	}
	return (count);
}
