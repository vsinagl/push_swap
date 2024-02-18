/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:43:01 by vsinagl           #+#    #+#             */
/*   Updated: 2023/12/02 20:41:08 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	options(const char *input, va_list args)
{
	if (*input == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (*input == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*input == 'p')
		return (ft_pointeradr(va_arg(args, void *)));
	else if (*input == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (*input == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (*input == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	else if (*input == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (*input == 'X')
		return (ft_puthex(va_arg(args, unsigned long int), 1));
	else if (*input == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, 0);
	while (*input != '\0')
	{
		if (*input == '%')
			count += options(++input, args);
		else
		{
			write(1, &(*input), 1);
			count++;
		}
		input++;
	}
	va_end(args);
	return (count);
}
