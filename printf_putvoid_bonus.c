/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putvoid_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:48:21 by lupalomi          #+#    #+#             */
/*   Updated: 2026/04/30 12:50:06 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*hex_converter(char *buffer, unsigned long ptr)
{
	char	*hex_digits;
	int		count;

	hex_digits = "0123456789abcdef";
	count = 18;
	buffer[count] = '\0';
	if (!ptr)
		buffer[--count] = '0';
	while (ptr > 0)
	{
		buffer[--count] = hex_digits[ptr % 16];
		ptr /= 16;
	}
	buffer[--count] = 'x';
	buffer[--count] = '0';
	return (&buffer[count]);
}

int	printf_putvoid_bonus(const void *ptr, t_format format)
{
	char	buffer[19];
	char	*str;
	int		printed;
	int		len;

	printed = 0;
	if (!ptr)
		return (printf_putstr_bonus("(nil)", format));
	str = hex_converter(buffer, (unsigned long)ptr);
	len = ft_strlen(str);
	if (!format.minus)
		printed += manage_padding(format.width, len);
	printed += printf_putstr(str);
	if (format.minus)
		printed += manage_padding(format.width, len);
	return (printed);
}
