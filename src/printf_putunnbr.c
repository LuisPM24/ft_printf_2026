/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putunnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 09:30:12 by lupalomi          #+#    #+#             */
/*   Updated: 2026/04/29 09:35:19 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putunnbr(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr >= 10)
		len += printf_putunnbr(nbr / 10);
	len += printf_putchar((nbr % 10) + '0');
	return (len);
}
