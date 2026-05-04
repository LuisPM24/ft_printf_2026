/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar_functions_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:45:06 by lupalomi          #+#    #+#             */
/*   Updated: 2026/05/04 17:45:07 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	aux_printf_putchar_bonus(const char chr)
{
	write(1, &chr, 1);
	return (1);
}

int	aux_printf_putstr_bonus(const char *str)
{
	int	count;

	if (!str)
		return (aux_printf_putstr_bonus("(null)"));
	count = 0;
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

int	aux_printf_putnbr_bonus(int nbr)
{
	int	len;

	len = 0;
	if (nbr == -2147483648)
		return (aux_printf_putstr_bonus("-2147483648"));
	if (nbr < 0)
	{
		len += aux_printf_putchar_bonus('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		len += aux_printf_putnbr_bonus(nbr / 10);
	len += aux_printf_putchar_bonus((nbr % 10) + '0');
	return (len);
}

int	aux_printf_putlwrhex_bonus(unsigned int nbr)
{
	char	buffer[9];
	char	*hex_digits;
	int		count;

	hex_digits = "0123456789abcdef";
	count = 8;
	buffer[count] = '\0';
	if (!nbr)
		return (aux_printf_putstr_bonus("0"));
	while (nbr > 0)
	{
		buffer[--count] = hex_digits[nbr % 16];
		nbr /= 16;
	}
	return (aux_printf_putstr_bonus(&buffer[count]));
}

int	aux_printf_putupphex_bonus(unsigned int nbr)
{
	char	buffer[9];
	char	*hex_digits;
	int		count;

	hex_digits = "0123456789ABCDEF";
	count = 8;
	buffer[count] = '\0';
	if (!nbr)
		return (aux_printf_putstr_bonus("0"));
	while (nbr > 0)
	{
		buffer[--count] = hex_digits[nbr % 16];
		nbr /= 16;
	}
	return (aux_printf_putstr_bonus(&buffer[count]));
}
