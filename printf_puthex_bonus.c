/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_puthex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:42:23 by lupalomi          #+#    #+#             */
/*   Updated: 2026/04/30 13:42:24 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	printf_putlwrhex_bonus(unsigned int nbr, t_format format)
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
	return (printf_putstr_bonus(&buffer[count], format));
}

int	printf_putupphex_bonus(unsigned int nbr, t_format format)
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
	return (printf_putstr_bonus(&buffer[count], format));
}
