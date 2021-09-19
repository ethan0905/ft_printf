/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 09:04:05 by esafar            #+#    #+#             */
/*   Updated: 2021/09/19 15:26:05 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	initialize(t_data flags)
{
	flags.zero = 0;
	flags.minus = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.dot = -1;
	flags.hashtag = 0;
	flags.size = 0;
	flags.precision = 0;
	flags.specifier = 0;
	flags.deja_vu = 0;
	return (flags);
}

int	treat(t_data flags, int specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = do_char(va_arg(ap, int), flags);
	else if (specifier == 's')
		count = do_string(va_arg(ap, char *), flags);
	else if (specifier == 'p')
		count = do_pointer(va_arg(ap, unsigned long long), flags);
	else if (specifier == 'd' || specifier == 'i')
		count = do_int(va_arg(ap, int), flags);
	else if (specifier == 'u')
		count = do_unsignedint(va_arg(ap, unsigned int), flags);
	else if (specifier == 'x')
		count = do_hexa(va_arg(ap, unsigned int), flags, 1);
	else if (specifier == 'X')
		count = do_hexa(va_arg(ap, unsigned int), flags, 0);
	else if (specifier == '%')
		count = do_percent(flags);
	return (count);
}

int	parsing(const char *str, t_data *flags, int i)
{
	while (ft_isnumber(str[i]) || ft_isflag(str[i]) || ft_iscspdiuxX(str[i]))
	{
		if (str[i] == '0' && flags->minus == 0 && flags->deja_vu != 1)
			flags->zero = 1;
		if (str[i] == '-')
			*flags = flagminus(*flags);
		if (str[i] == ' ' || str[i] == '+' || str[i] == '#')
			*flags = flagsimple(str[i], *flags);
		if (str[i] == '.')
			i = flagdot(str, *flags, i);
		if (ft_isnumber(str[i]))
			*flags = flagnumber(str[i], *flags);
		if (ft_iscspdiuxX(str[i]))
		{
			flags->specifier = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

int	ft_check_str(const char *str, va_list ap)
{
	int		i;
	int		count;
	t_data	flags;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		flags = initialize(flags);
		if (str[i] == '%' && str[i + 1])
		{
			i = parsing(str, &flags, ++i);
			if (ft_iscspdiuxX(str[i]))
				count += treat(flags, flags.specifier, ap);
			else if (str[i])
				count += ft_putchar(str[i]);
		}
		else if (str[i] != '%')
			count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, str);
	count = ft_check_str(str, ap);
	va_end(ap);
	return (count);
}
