/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:45:12 by lupalomi          #+#    #+#             */
/*   Updated: 2026/04/30 11:47:08 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"

typedef struct s_format
{
	int		minus;
	int		zero;
	int		dot;
	int		precision;
	int		width;
	int		hash;
	int		space;
	int		plus;
	char	chr;
}	t_format;

// Bonus
void	init_format(t_format *format);
int		ft_strlen(const char *str);
int		is_flag(char chr);
void	parse_format(const char *str, int *pos, t_format *format);
int		manage_padding(int padd, int amount);
int		printf_putchar_bonus(char chr, t_format format);
int		printf_putstr_bonus(char *str, t_format format);
int		printf_putvoid_bonus(const void *ptr, t_format format);
int		printf_putnbr_bonus(int nbr, t_format format);
int		printf_putunnbr_bonus(unsigned int nbr, t_format format);
int		printf_putlwrhex_bonus(unsigned int nbr, t_format format);
int		printf_putupphex_bonus(unsigned int nbr, t_format format);

#endif
