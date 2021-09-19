/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 10:52:18 by esafar            #+#    #+#             */
/*   Updated: 2021/09/19 15:23:41 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*ft_putintab2(char *number, long nbr, int len, int sign)
{
	if (nbr != 0)
		number = malloc(sizeof(char) * (len + 1));
	else
		return (number = ft_strdup("0"));
	if (!number)
		return (0);
	sign = 0;
	if (nbr < 0)
	{
		sign++;
		nbr = -nbr;
	}
	number[len] = '\0';
	while (--len)
	{
		number[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (sign == 1)
		number[0] = '-';
	else
		number[0] = (nbr % 10) + '0';
	return (number);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*number;
	long	nbr;
	int		sign;

	nbr = n;
	len = ft_intlen(nbr);
	number = NULL;
	sign = 0;
	number = ft_putintab2(number, nbr, len, sign);
	if (!number)
		return (0);
	return (number);
}
