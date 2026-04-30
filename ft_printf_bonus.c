
#include "ft_printf_bonus.h"

static int	option_selector_bonus(va_list ap, t_format format)
{
	if (format.chr == 'c')
		return (printf_putchar((char)va_arg(ap, int)));
	if (format.chr == 's')
		return (printf_putstr(va_arg(ap, char *)));
	if (format.chr == 'p')
		return (printf_putvoid(va_arg(ap, void *)));
	if (format.chr == 'd' || format.chr == 'i')
		return (printf_putnbr(va_arg(ap, int)));
	if (format.chr == 'u')
		return (printf_putunnbr(va_arg(ap, unsigned int)));
	if (format.chr == 'x')
		return (printf_putlwrhex(va_arg(ap, unsigned int)));
	if (format.chr == 'X')
		return (printf_putupphex(va_arg(ap, unsigned int)));
	if (format.chr == '%')
		return (printf_putchar('%'));
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