/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_width_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:39:59 by lupalomi          #+#    #+#             */
/*   Updated: 2026/04/30 11:44:11 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	manage_padding(int padd, int amount)
{
	int	printed;

	printed = 0;
	while (padd > amount)
	{
		printed += write(1, " ", 1);
		padd--;
	}
	return (printed);
}

int	manage_padding_char(int width, int len, char c)
{
	int	printed;

	printed = 0;
	while (width > len)
	{
		printed += aux_printf_putchar_bonus(c);
		width--;
	}
	return (printed);
}

int	print_zeroes(int amount_zero)
{
	int	printed;

	printed = 0;
	while (amount_zero > 0)
	{
		printed += aux_printf_putchar_bonus('0');
		amount_zero--;
	}
	return (printed);
}
