/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:19:52 by lupalomi          #+#    #+#             */
/*   Updated: 2026/04/28 18:20:04 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putnbr(int nbr)
{
	int	len;

	len = 0;
	if (nbr == -2147483648)
		return (printf_putstr("-2147483648"));
	if (nbr < 0)
	{
		len += printf_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		len += printf_putnbr(nbr / 10);
	len += printf_putchar((nbr % 10) + '0');
	return (len);
}
