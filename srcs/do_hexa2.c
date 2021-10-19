/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_hexa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 10:37:27 by esafar            #+#    #+#             */
/*   Updated: 2021/09/20 10:17:47 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h" 

int	flaghashtag(int nb, int count, int lower)
{
	if (nb != 0 && lower == 1)
		count += do_precision("0x", 2);
	else if (nb != 0 && lower == 0)
		count += do_precision("0X", 2);
	count += ft_puthexa(nb, lower);
	return (count);
}

int	flagminus2(int nb, t_var var, int lower, t_data flags)
{
	var.count += ft_puthexa(nb, lower);
	var.diff = flags.size - var.count;
	while (var.diff-- > 0)
		var.count += ft_putchar(' ');
	return (var.count);
}

int	flagzero(int nb, t_var var, int lower, t_data flags)
{
	var.len = ft_putpasmonhexa(nb, lower);
	var.diff = flags.size - var.len;
	while (var.diff-- > 0)
		var.count += ft_putchar('0');
	var.count += ft_puthexa(nb, lower);
	return (var.count);
}
