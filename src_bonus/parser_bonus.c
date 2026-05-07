/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:44:50 by lupalomi          #+#    #+#             */
/*   Updated: 2026/04/30 11:44:55 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	normalize_format(t_format *format)
{
	if (format->minus)
		format->zero = 0;
	if (format->dot && (format->chr == 'd' || format->chr == 'i'
			|| format->chr == 'u' || format->chr == 'x'
			|| format->chr == 'X'))
		format->zero = 0;
	if (format->plus)
		format->space = 0;
}

static void	parse_width(const char *str, int *pos, t_format *format)
{
	while (str[*pos] >= '0' && str[*pos] <= '9')
	{
		format->width = format->width * 10 + (str[*pos] - '0');
		(*pos)++;
	}
}

static void	parse_precision(const char *str, int *pos, t_format *format)
{
	if (str[*pos] == '.')
	{
		format->dot = 1;
		(*pos)++;
		while (str[*pos] >= '0' && str[*pos] <= '9')
		{
			format->precision = format->precision * 10 + (str[*pos] - '0');
			(*pos)++;
		}
	}
}

static void	parse_flags(const char *str, int *pos, t_format *format)
{
	while (is_flag(str[*pos]))
	{
		if (str[*pos] == '-')
			format->minus = 1;
		else if (str[*pos] == '0')
			format->zero = 1;
		else if (str[*pos] == '#')
			format->hash = 1;
		else if (str[*pos] == ' ')
			format->space = 1;
		else if (str[*pos] == '+')
			format->plus = 1;
		(*pos)++;
	}
}

void	parse_format(const char *str, int *pos, t_format *format)
{
	init_format(format);
	(*pos)++;
	parse_flags(str, pos, format);
	parse_width(str, pos, format);
	parse_precision(str, pos, format);
	format->chr = str[*pos];
	normalize_format(format);
}
