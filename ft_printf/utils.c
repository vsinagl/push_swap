/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:43:01 by vsinagl           #+#    #+#             */
/*   Updated: 2023/12/02 20:41:08 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int		i;

	i = 0;
	if (s == NULL)
		s = "(null)";
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int num)
{
	int	count;
	int	mod;

	count = 0;
	if (num < 0)
	{
		count += ft_putchar('-');
		if (num == INT_MIN)
		{
			count += ft_putstr("2147483648");
			return (count);
		}
		num = num * (-1);
	}
	mod = num % 10;
	if (num / 10 > 0)
		count += ft_putnbr(num / 10);
	count += ft_putchar(mod + '0');
	return (count);
}

int	ft_putnbr_u(unsigned int num)
{
	int	count;
	int	mod;

	count = 0;
	mod = num % 10;
	if (num / 10 > 0)
		count += ft_putnbr_u(num / 10);
	count += ft_putchar(mod + '0');
	return (count);
}

int	ft_puthex(unsigned int num, int option)
{
	char	*upper;
	char	*lower;
	int		count;

	upper = "0123456789ABCDEF";
	lower = "0123456789abcdef";
	count = 0;
	if (num > 15)
		count += ft_puthex(num / 16, option);
	if (option == 1)
		count += ft_putchar(upper[num % 16]);
	else
		count += ft_putchar(lower[num % 16]);
	return (count);
}
