/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putvoid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:41:50 by lupalomi          #+#    #+#             */
/*   Updated: 2026/04/28 18:07:16 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	printf_putvoid(const void *ptr)
{
	char	buffer[19];

	if (!ptr)
		return (printf_putstr("(nil)"));
	return (printf_putstr(hex_converter(buffer, (unsigned long)ptr)));
}
