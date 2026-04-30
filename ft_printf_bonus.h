
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
int		is_flag(char chr);
void	parse_format(const char *str, int *pos, t_format *format);

#endif
