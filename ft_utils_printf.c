/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamtafe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:26:40 by alamtafe          #+#    #+#             */
/*   Updated: 2026/10/27 16:26:42 by alamtafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	return (count + 1);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	return (count + 1);
}

int	ft_puthex_ptr(void *p)
{
	char			*s;
	int				count;
	unsigned long	a;

	if (!p)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 0;
	s = "0123456789abcdef";
	a = (unsigned long)p;
	if (a >= 16)
	{
		count += ft_puthex_ptr((void *)(a / 16));
	}
	if (a < 16)
	{
		write(1, "0x", 2);
		count += 2;
	}
	write(1, &s[a % 16], 1);
	count++;
	return (count);
}
