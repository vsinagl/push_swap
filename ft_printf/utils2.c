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

int	ft_puthex_p(unsigned long int num)
{
	char	*lower;
	int		count;

	lower = "0123456789abcdef";
	count = 0;
	if (num > 15)
		count += ft_puthex_p(num / 16);
	count += ft_putchar(lower[num % 16]);
	return (count);
}

int	ft_pointeradr(void *ptr)
{
	int						count;
	unsigned long int		adr;

	count = 0;
	adr = 0;
	if (ptr == NULL)
		count += ft_putstr("(nil)");
	else
	{
		adr = (unsigned long int)ptr;
		count += ft_putstr("0x");
		count += ft_puthex_p(adr);
	}
	return (count);
}
