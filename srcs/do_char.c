/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 10:49:43 by esafar            #+#    #+#             */
/*   Updated: 2021/09/20 14:26:51 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	do_size(int size, int diff, int has_zero)
{
	int	count;

	count = 0;
	while (size - diff > 0)
	{
		if (has_zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		size--;
		count++;
	}
	return (count);
}

int	do_char(char c, t_data flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	count = do_size(flags.size, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (count + 1);
}
