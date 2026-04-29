/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:03:20 by lupalomi          #+#    #+#             */
/*   Updated: 2026/04/29 09:29:43 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	option_selector(va_list ap, char chr)
{
	if (chr == 'c')
		return (printf_putchar((char)va_arg(ap, int)));
	if (chr == 's')
		return (printf_putstr(va_arg(ap, char *)));
	if (chr == 'p')
		return (printf_putvoid(va_arg(ap, void *)));
	if (chr == 'd' || chr == 'i')
		return (printf_putnbr(va_arg(ap, int)));
	if (chr == 'u')
		return (printf_putunnbr(va_arg(ap, unsigned int)));
	if (chr == 'x')
		return (printf_putlwrhex(va_arg(ap, unsigned int)));
	if (chr == 'X')
		return (printf_putupphex(va_arg(ap, unsigned int)));
	if (chr == '%')
		return (printf_putchar('%'));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	int		count;
	int		len;
	va_list	ap;

	count = 0;
	len = 0;
	va_start(ap, str);
	while (str[count])
	{
		if (str[count] == '%' && str[count + 1])
		{
			len += option_selector(ap, str[count + 1]);
			count++;
		}
		else
		{
			write(1, &str[count], 1);
			len++;
		}
		count++;
	}
	va_end(ap);
	return (len);
}
