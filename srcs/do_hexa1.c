/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_hexa1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 10:38:14 by esafar            #+#    #+#             */
/*   Updated: 2021/09/20 14:20:50 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	init(t_var *var)
{
	var->len = 0;
	var->count = 0;
	var->diff = 0;
}

int	ft_puthexa(unsigned int nb, int lower)
{
	static int	count;
	char		*base_lower;
	char		*base_upper;

	count = 0;
	base_lower = ft_strdup("0123456789abcdef");
	base_upper = ft_strdup("0123456789ABCDEF");
	if (nb == 0)
		count += ft_putchar('0');
	if (nb >= 16)
		ft_puthexa(nb / 16, lower);
	if (lower == 1 && nb != 0)
		count += ft_putchar(base_lower[nb % 16]);
	else if (lower == 0 && nb != 0)
		count += ft_putchar(base_upper[nb % 16]);
	free(base_lower);
	free(base_upper);
	return (count);
}

int	ft_putpasmonhexa(unsigned int nb, int lower)
{
	static int	count;

	count = 0;
	if (nb == 0)
		count++;
	if (nb >= 16)
		ft_putpasmonhexa(nb / 16, lower);
	if (lower == 1 && nb != 0)
		count++;
	else if (lower == 0 && nb != 0)
		count++;
	return (count);
}

int	do_hexa(unsigned int nb, t_data flags, int lower)
{
	t_var	var;

	init(&var);
	if (flags.hashtag == 1)
		var.count = flaghashtag(nb, var.count, lower);
	else if (flags.minus == 1)
		var.count = flagminus2(nb, var, lower, flags);
	else if (flags.zero == 1)
		var.count = flagzero(nb, var, lower, flags);
	else
	{
		var.len = ft_putpasmonhexa(nb, lower);
		if (flags.dot > flags.zero)
			var.diff = flags.dot - var.len;
		while (var.diff-- > 0)
			var.count += ft_putchar('0');
		var.count += ft_puthexa(nb, lower);
	}
	return (var.count);
}
