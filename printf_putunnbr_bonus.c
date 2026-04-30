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

	len = 0;
	if (nbr == 4294967295)
		return (10);
	if (nbr >= 10)
		len += calc_size(nbr / 10);
	len++;
	return (len);
}

int	printf_putunnbr_bonus(unsigned int nbr, t_format format)
{
	int	printed;

	printed = 0;
	if (!format.minus)
		printed += manage_padding(format.width, calc_size(nbr));
	printed += printf_putunnbr(nbr);
	if (format.minus)
		printed += manage_padding(format.width, calc_size(nbr));
	return (printed);
}
