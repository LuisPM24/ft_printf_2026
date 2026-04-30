/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:46:12 by lupalomi          #+#    #+#             */
/*   Updated: 2026/04/30 11:46:14 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	option_selector_bonus(va_list ap, t_format format)
{
	if (format.chr == 'c')
		return (printf_putchar_bonus((char)va_arg(ap, int), format));
	if (format.chr == 's')
		return (printf_putstr_bonus(va_arg(ap, char *), format));
	if (format.chr == 'p')
		return (printf_putvoid_bonus(va_arg(ap, void *), format));
	if (format.chr == 'd' || format.chr == 'i')
		return (printf_putnbr_bonus(va_arg(ap, int), format));
	if (format.chr == 'u')
		return (printf_putunnbr_bonus(va_arg(ap, unsigned int), format));
	if (format.chr == 'x')
		return (printf_putlwrhex_bonus(va_arg(ap, unsigned int), format));
	if (format.chr == 'X')
		return (printf_putupphex_bonus(va_arg(ap, unsigned int), format));
	if (format.chr == '%')
		return (printf_putchar_bonus('%', format));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list		ap;
	t_format	format;
	int			position;
	int			len;

	position = 0;
	len = 0;
	va_start(ap, str);
	while (str[position])
	{
		if (str[position] == '%' && str[position + 1])
		{
			parse_format(str, &position, &format);
			len += option_selector_bonus(ap, format);
		}
		else
		{
			write(1, &str[position], 1);
			len++;
		}
		position++;
	}
	va_end(ap);
	return (len);
}

#include <stdio.h>

int main(void)
{
	unsigned int	aux;

	aux = 42;
	ft_printf("|%22x|\n", aux);
	printf("|%22x|\n", aux);
	return (0);
}