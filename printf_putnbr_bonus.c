/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putnbr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:17:51 by lupalomi          #+#    #+#             */
/*   Updated: 2026/04/30 13:17:52 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	calc_size(int nbr)
{
	int	len;

	len = 0;
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	if (nbr >= 10)
		len += calc_size(nbr / 10);
	len++;
	return (len);
}

int	printf_putnbr_bonus(int nbr, t_format format)
{
	int	printed;

	printed = 0;
	if (!format.minus)
		printed += manage_padding(format.width, calc_size(nbr));
	printed += printf_putnbr(nbr);
	if (format.minus)
		printed += manage_padding(format.width, calc_size(nbr));
	return (printed);
}
