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

	len = 1;
	if (nbr == -2147483648)
		return (10);
	if (nbr < 0)
		nbr = -nbr;
	while (nbr >= 10)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static int	calc_total_len(int nbr, t_format format, int *amount_zero)
{
	int	size;
	int	total_len;

	size = calc_size(nbr);
	*amount_zero = 0;
	if (format.dot && format.precision > size)
		*amount_zero = format.precision - size;
	total_len = size + *amount_zero;
	if (nbr < 0)
		total_len++;
	if (format.dot && format.precision == 0 && nbr == 0)
		total_len = 0;
	return (total_len);
}

int	printf_putnbr_bonus(int nbr, t_format format)
{
	int	printed;
	int	amount_zero;
	int	total_len;

	printed = 0;
	total_len = calc_total_len(nbr, format, &amount_zero);
	if (!format.minus)
		printed += manage_padding(format.width, total_len);
	if (nbr < 0 && total_len > 0)
		printed += printf_putchar('-');
	while (amount_zero > 0)
	{
		printed += printf_putchar('0');
		amount_zero--;
	}
	if (!(format.dot && format.precision == 0 && nbr == 0))
	{
		if (nbr > 0)
			printed += printf_putnbr(nbr);
		else
			printed += printf_putnbr(-nbr);
	}
	if (format.minus)
		printed += manage_padding(format.width, total_len);
	return (printed);
}
