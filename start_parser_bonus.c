#include "ft_printf_bonus.h"

void	init_format(t_format *format)
{
	format->minus = 0;
	format->zero = 0;
	format->dot = 0;
	format->precision = 0;
	format->width = 0;
	format->hash = 0;
	format->space = 0;
	format->plus = 0;
	format->chr = 0;
}

int	is_flag(char chr)
{
	return (chr == '-' || chr == '0' || chr == '#' || chr == ' '
		|| chr == '+');
}