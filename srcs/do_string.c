/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 10:48:54 by esafar            #+#    #+#             */
/*   Updated: 2021/09/20 10:19:03 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	do_precision(char *str, int precision)
{
	int	count;

	count = 0;
	while (str[count] && count < precision)
		ft_putchar(str[count++]);
	return (count);
}

int	adjust(char *str, t_data flags)
{
	int	count;

	count = 0;
	if (flags.dot >= 0)
	{
		count += do_size(flags.dot, ft_strlen(str), 0);
		count += do_precision(str, flags.dot);
	}
	else
		count += do_precision(str, ft_strlen(str));
	return (count);
}

int	do_string(char *str, t_data flags)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		count += adjust(str, flags);
	if (flags.dot >= 0)
		count += do_size(flags.size, flags.dot, 0);
	else
		count += do_size(flags.size, ft_strlen(str), 0);
	if (flags.minus == 0)
		count += adjust(str, flags);
	return (count);
}
