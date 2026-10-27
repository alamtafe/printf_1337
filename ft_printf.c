/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamtafe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:22:19 by alamtafe          #+#    #+#             */
/*   Updated: 2026/10/27 16:22:34 by alamtafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char *s)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, s);
	write(1, &s[n % 16], 1);
	return (count + 1);
}

int	refrence(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'p')
		count += ft_puthex_ptr(va_arg(args, void *));
	else if (c == 'x')
		count += ft_puthex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count += ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
	{
		write(1, "%", 1);
		count++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		else
		{
			i++;
			count += refrence(format[i], args);
		}
		i++;
	}
	va_end(args);
	return (count);
}
