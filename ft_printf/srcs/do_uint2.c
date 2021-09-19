/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_uint2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 10:02:51 by esafar            #+#    #+#             */
/*   Updated: 2021/09/19 12:32:50 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	do_special2(char *number, t_data flags)
{
	int	count;

	count = 0;
	if (flags.dot >= 0)
		count += do_size(flags.dot - 1, ft_strlen(number) - 1, 1);
	count += do_precision(number, ft_strlen(number));
	return (count);
}
