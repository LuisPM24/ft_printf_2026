/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putstr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:49:42 by lupalomi          #+#    #+#             */
/*   Updated: 2026/04/30 11:57:15 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	printf_putchar_bonus(char chr, t_format format)
{
	int	printed;

	printed = 0;
	if (!format.minus)
		printed += manage_padding(format.width, 1);
	printed += printf_putchar(chr);
	if (format.minus)
		printed += manage_padding(format.width, 1);
	return (printed);
}

int	printf_putstr_bonus(char *str, t_format format)
{
	int	printed;
	int	len;

	printed = 0;
	len = 0;
	if (!str)
		printf_putstr_bonus("(null)", format);
	len = ft_strlen(str);
	if (!format.minus)
		printed += manage_padding(format.width, len);
	printed += printf_putstr(str);
	if (format.minus)
		printed += manage_padding(format.width, len);
	return (printed);
}