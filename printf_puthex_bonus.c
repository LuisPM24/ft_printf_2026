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

static int	print_hex_prefix(char type)
{
	if (type == 'x')
		return (aux_printf_putstr_bonus("0x"));
	return (aux_printf_putstr_bonus("0X"));
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
	if (format.hash && nbr != 0)
		total_len += 2;
	return (total_len);
}

int	printf_putlwrhex_bonus(unsigned int nbr, t_format format)
{
	int	printed;
	int	amount_zero;
	int	total_len;

	printed = 0;
	total_len = calc_total_len(nbr, format, &amount_zero);
	if (!format.minus && format.zero && format.hash && nbr != 0)
	{
		printed += print_hex_prefix('x');
		printed += manage_padding_char(format.width, total_len, '0');
	}
	else if (!format.minus && format.zero)
		printed += manage_padding_char(format.width, total_len, '0');
	else if (!format.minus)
		printed += manage_padding(format.width, total_len);
	if (!(format.zero && format.hash && nbr != 0)
		&& format.hash && nbr != 0)
		printed += print_hex_prefix('x');
	printed += print_zeroes(amount_zero);
	if (!(format.dot && format.precision == 0 && nbr == 0))
		printed += aux_printf_putlwrhex_bonus(nbr);
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
	if (!format.minus && format.zero && format.hash && nbr != 0)
	{
		printed += print_hex_prefix('X');
		printed += manage_padding_char(format.width, total_len, '0');
	}
	else if (!format.minus && format.zero)
		printed += manage_padding_char(format.width, total_len, '0');
	else if (!format.minus)
		printed += manage_padding(format.width, total_len);
	if (!(format.zero && format.hash && nbr != 0)
		&& format.hash && nbr != 0)
		printed += print_hex_prefix('X');
	printed += print_zeroes(amount_zero);
	if (!(format.dot && format.precision == 0 && nbr == 0))
		printed += aux_printf_putupphex_bonus(nbr);
	if (format.minus)
		printed += manage_padding(format.width, total_len);
	return (printed);
}
