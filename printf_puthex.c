/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_puthex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 09:39:59 by lupalomi          #+#    #+#             */
/*   Updated: 2026/04/29 09:57:58 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putlwrhex(unsigned int nbr)
{
	char	buffer[9];
	char	*hex_digits;
	int		count;

	hex_digits = "0123456789abcdef";
	count = 8;
	buffer[count] = '\0';
	if (!nbr)
		return (printf_putstr("0"));
	while (nbr > 0)
	{
		buffer[--count] = hex_digits[nbr % 16];
		nbr /= 16;
	}
	return (printf_putstr(&buffer[count]));
}

int	printf_putupphex(unsigned int nbr)
{
	char	buffer[9];
	char	*hex_digits;
	int		count;

	hex_digits = "0123456789ABCDEF";
	count = 8;
	buffer[count] = '\0';
	if (!nbr)
		return (printf_putstr("0"));
	while (nbr > 0)
	{
		buffer[--count] = hex_digits[nbr % 16];
		nbr /= 16;
	}
	return (printf_putstr(&buffer[count]));
}
