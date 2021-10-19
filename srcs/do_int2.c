/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_int2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 10:47:48 by esafar            #+#    #+#             */
/*   Updated: 2021/09/20 10:18:12 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	monplus(int nb, t_data flags, int count)
{
	if (nb >= 0 && flags.minus == 0)
		count += ft_putchar('+');
	else if (nb >= 0 && flags.minus == 1)
		ft_putchar('+');
	return (count);
}

int	monpoint(t_data flags, int count)
{
	count += do_size(flags.size, 0, 0);
	return (count);
}

int	monmoins(int nb, t_data flags, int count)
{
	if (flags.zero == 1 && flags.dot == -1 && nb != INT_MIN)
		do_precision("-", 1);
	nb = -nb;
	count++;
	flags.zero = 1;
	flags.size--;
	return (count);
}
