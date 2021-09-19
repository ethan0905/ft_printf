/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_int1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 10:39:19 by esafar            #+#    #+#             */
/*   Updated: 2021/09/19 12:31:41 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	do_special(char *number, int save, t_data flags)
{
	int	count;

	count = 0;
	if (save < 0 && flags.dot >= 0 && save != INT_MIN)
		ft_putchar('-');
	if (flags.dot >= 0)
		count += do_size(flags.dot - 1, ft_strlen(number) - 1, 1);
	count += do_precision(number, ft_strlen(number));
	return (count);
}

static int	adjust_int(char *number, int save, t_data flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count += do_special(number, save, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(number))
		flags.dot = ft_strlen(number);
	if (flags.dot >= 0)
	{
		flags.size = flags.size - flags.dot;
		count += do_size(flags.size, 0, 0);
	}
	else
	{
		count += do_size(flags.size, ft_strlen(number), flags.zero);
	}
	if (flags.minus == 0)
		count += do_special(number, save, flags);
	return (count);
}

int	do_int(int nb, t_data flags)
{
	int		count;
	char	*number;
	int		save;

	count = 0;
	save = nb;
	if (flags.plus == 1)
		count = monplus(nb, flags, count);
	if (flags.dot == 0 && nb == 0)
		count = monpoint(nb, flags, count);
	if (nb < 0 && (flags.dot >= 0 || flags.zero == 1))
		count = monmoins(nb, flags, count);
	if (flags.space == 1 && save >= 0 && flags.plus == 0)
	{
		ft_putchar(' ');
		count++;
	}
	if (nb == INT_MIN && flags.zero == 1)
		count--;
	number = ft_itoa(nb);
	count += adjust_int(number, save, flags);
	free(number);
	return (count);
}
