/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putper_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:13:50 by lupalomi          #+#    #+#             */
/*   Updated: 2026/05/04 16:13:51 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	printf_percent_bonus(t_format format)
{
	int		printed;
	char	padd;

	printed = 0;
	padd = ' ';
	if (format.zero && !format.minus)
		padd = '0';
	if (!format.minus)
		printed += manage_padding_char(format.width, 1, padd);
	printed += aux_printf_putchar_bonus('%');
	if (format.minus)
		printed += manage_padding(format.width, 1);
	return (printed);
}
