/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pointer1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 10:04:45 by esafar            #+#    #+#             */
/*   Updated: 2021/09/19 12:32:07 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*write_tab(unsigned long long save, int base, char *tab, int i)
{
	while (save != 0)
	{
		if (save % base < 10)
			tab[i - 1] = (save % base) + 48;
		else
			tab[i - 1] = (save % base) + 55;
		save = save / base;
		i--;
	}
	return (tab);
}

char	*ullbase(unsigned long long nb, int base)
{
	int					i;
	char				*tab;
	unsigned long long	save;

	i = 0;
	tab = NULL;
	save = nb;
	if (nb == 0)
	{
		tab = ft_strdup("0");
		return (tab);
	}
	while (nb != 0)
	{
		nb = nb / base;
		i++;
	}
	tab = (char *)malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (0);
	tab[i] = '\0';
	tab = write_tab(save, base, tab, i);
	return (tab);
}

static int	adjust_ptr(char *ptr, t_data flags)
{
	int	count;

	count = 0;
	count += do_precision("0x", 2);
	if (flags.dot >= 0)
	{
		count += do_size(flags.dot, ft_strlen(ptr), 1);
		count += do_precision(ptr, flags.dot);
	}
	else
		count += do_precision(ptr, ft_strlen(ptr));
	return (count);
}

int	do_pointer(unsigned long long nb, t_data flags)
{
	int		count;
	char	*ptr;

	count = 0;
	if (nb == 0 && flags.dot == 0)
	{
		count += do_precision("0x", 2);
		count += do_size(flags.size, 0, 1);
		return (count);
	}
	ptr = ullbase(nb, 16);
	ptr = ft_str_tolower(ptr);
	if ((size_t)flags.dot < ft_strlen(ptr))
		flags.dot = ft_strlen(ptr);
	if (flags.minus == 1)
		count += adjust_ptr(ptr, flags);
	count += do_size(flags.size, ft_strlen(ptr) + 2, 0);
	if (flags.minus == 0)
		count += adjust_ptr(ptr, flags);
	free(ptr);
	return (count);
}
