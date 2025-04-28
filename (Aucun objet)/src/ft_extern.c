/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extern.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 02:20:08 by loicpapon         #+#    #+#             */
/*   Updated: 2025/04/28 02:21:42 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	hexa(long n, int maj)
{
	int		count;
	char	*base;

	count = 1;
	if (maj == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		count = hexa(n / 16, maj);
		n = n % 16;
		count++;
	}
	write(1, &base[n], 1);
	return (count);
}

int	adr_hexa(unsigned long n)
{
	int		count;
	char	*base;

	count = 1;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		count = adr_hexa(n / 16);
		n = n % 16;
		count++;
	}
	write(1, &base[n], 1);
	return (count);
}

int	ft_putnbr(long n)
{
	int		count;

	count = 1;
	if (n < 0)
	{
		n = n * -1;
		count += write(1, "-", 1);
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		n = n % 10;
	}
	n = n + '0';
	write(1, &n, 1);
	return (count);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
