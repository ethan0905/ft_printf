/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:35:07 by esafar            #+#    #+#             */
/*   Updated: 2021/09/19 11:46:31 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	flagminus(t_data flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

int	flagdot(const char *str, t_data flags, int i)
{
	flags.dot = 0;
	i++;
	while (ft_isnumber(str[i]))
	{
		flags.deja_vu = 1;
		flags.dot = (flags.dot * 10) + (str[i] - '0');
		i++;
	}
	return (i);
}

t_data	flagnumber(char c, t_data flags)
{
	flags.deja_vu = 1;
	flags.size = (flags.size * 10) + (c - '0');
	return (flags);
}

t_data	flagsimple(char c, t_data flags)
{
	if (c == ' ')
		flags.space = 1;
	if (c == '+')
		flags.plus = 1;
	if (c == '#')
		flags.hashtag = 1;
	return (flags);
}
