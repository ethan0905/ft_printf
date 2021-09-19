/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_uint1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 10:02:06 by esafar            #+#    #+#             */
/*   Updated: 2021/09/19 12:32:40 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	adjust_uint(char *number, t_data flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count += do_special2(number, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(number))
		flags.dot = ft_strlen(number);
	if (flags.dot >= 0)
	{
		flags.size -= flags.dot;
		count += do_size(flags.size, 0, 0);
	}
	else
		count += do_size(flags.size, ft_strlen(number), flags.zero);
	if (flags.minus == 0)
		count += do_special2(number, flags);
	return (count);
}

static int	ft_uintlen(long n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n >= 1)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*ft_putintab(char *number, long nbr, int len, int sign)
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

char	*ft_u_itoa(unsigned int n)
{
	int		len;
	char	*number;
	long	nbr;
	int		sign;

	nbr = n;
	len = ft_uintlen(nbr);
	number = NULL;
	sign = 0;
	number = ft_putintab(number, nbr, len, sign);
	if (!number)
		return (0);
	return (number);
}

int	do_unsignedint(unsigned int nb, t_data flags)
{
	int		count;
	char	*number;

	count = 0;
	nb = (unsigned int)(4294967295 + 1 + nb);
	if (flags.dot == 0 && nb == 0)
	{
		count += do_size(flags.size, 0, 0);
		return (count);
	}
	number = ft_u_itoa(nb);
	count += adjust_uint(number, flags);
	free(number);
	return (count);
}
