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

static int	calc_size(unsigned int nbr)
{
	int	len;

	len = 1;
	while (nbr >= 16)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

static int	calc_total_len(unsigned int nbr, t_format format,
		int *amount_zero)
{
	int	size;
	int	total_len;

	size = calc_size(nbr);
	*amount_zero = 0;
	if (format.dot && format.precision > size)
		*amount_zero = format.precision - size;
	total_len = size + *amount_zero;
	if (format.dot && format.precision == 0 && nbr == 0)
		total_len = 0;
	return (total_len);
}

int	printf_putlwrhex_bonus(unsigned int nbr, t_format format)
{
	int	printed;
	int	amount_zero;
	int	total_len;

	printed = 0;
	total_len = calc_total_len(nbr, format, &amount_zero);
	if (!format.minus)
		printed += manage_padding(format.width, total_len);
	while (amount_zero > 0)
	{
		printed += printf_putchar('0');
		amount_zero--;
	}
	if (!(format.dot && format.precision == 0 && nbr == 0))
		printed += printf_putlwrhex(nbr);
	if (format.minus)
		printed += manage_padding(format.width, total_len);
	return (printed);
}

int	printf_putupphex_bonus(unsigned int nbr, t_format format)
{
	int	printed;
	int	amount_zero;
	int	total_len;

	printed = 0;
	total_len = calc_total_len(nbr, format, &amount_zero);
	if (!format.minus)
		printed += manage_padding(format.width, total_len);
	while (amount_zero > 0)
	{
		printed += printf_putchar('0');
		amount_zero--;
	}
	if (!(format.dot && format.precision == 0 && nbr == 0))
		printed += printf_putupphex(nbr);
	if (format.minus)
		printed += manage_padding(format.width, total_len);
	return (printed);
}
