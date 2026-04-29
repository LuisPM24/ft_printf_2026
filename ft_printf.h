/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:55:00 by lupalomi          #+#    #+#             */
/*   Updated: 2026/04/28 18:32:11 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *str, ...);
int	printf_putchar(const char chr);
int	printf_putstr(const char *str);
int	printf_putvoid(const void *ptr);
int	printf_putnbr(int nbr);
int	printf_putunnbr(unsigned int nbr);
int	printf_putlwrhex(unsigned int nbr);
int	printf_putupphex(unsigned int nbr);

#endif
