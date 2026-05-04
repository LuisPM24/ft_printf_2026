/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putunnbr_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:36:34 by lupalomi          #+#    #+#             */
/*   Updated: 2026/04/30 13:36:36 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	calc_size(unsigned int nbr)
{
	int	len;

	len = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
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

int	aux_printf_putunnbr_bonus(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr >= 10)
		len += aux_printf_putunnbr_bonus(nbr / 10);
	len += aux_printf_putchar_bonus((nbr % 10) + '0');
	return (len);
}

int	printf_putunnbr_bonus(unsigned int nbr, t_format format)
{
	int	printed;
	int	amount_zero;
	int	total_len;

	printed = 0;
	total_len = calc_total_len(nbr, format, &amount_zero);
	if (!format.minus && format.zero)
		printed += manage_padding_char(format.width, total_len, '0');
	else if (!format.minus)
		printed += manage_padding(format.width, total_len);
	while (amount_zero > 0)
	{
		printed += aux_printf_putchar_bonus('0');
		amount_zero--;
	}
	if (!(format.dot && format.precision == 0 && nbr == 0))
		printed += aux_printf_putunnbr_bonus(nbr);
	if (format.minus)
		printed += manage_padding(format.width, total_len);
	return (printed);
}
