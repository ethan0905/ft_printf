/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 12:21:26 by esafar            #+#    #+#             */
/*   Updated: 2021/09/19 12:30:55 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	do_percent(t_data flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count += do_precision("%", 1);
	count += do_size(flags.size, 1, flags.zero);
	if (flags.minus == 0)
		count += do_precision("%", 1);
	return (count);
}
