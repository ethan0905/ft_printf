/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:33:06 by esafar            #+#    #+#             */
/*   Updated: 2021/09/20 11:37:04 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_var
{
	int	len;
	int	count;
	int	diff;
}	t_var;

typedef struct s_data
{
	int	zero;
	int	minus;
	int	plus;
	int	space;
	int	dot;
	int	hashtag;
	int	size;
	int	specifier;
	int	deja_vu;
}	t_data;

int		ft_printf(const char *str, ...);
int		ft_check_str(const char *str, va_list ap);
int		parsing(const char *str, t_data *flags, int i);
int		treat(t_data flags, int specifier, va_list ap);
void	initialize(t_data *flags);
t_data	flagsimple(char c, t_data flags);
t_data	flagnumber(char c, t_data flags);
int		flagdot(const char *str, t_data flags, int i);
t_data	flagminus(t_data flags);

int		do_char(char c, t_data flags);
int		do_size(int size, int diff, int has_zero);

int		do_hexa(unsigned int nb, t_data flags, int lower);
int		ft_putpasmonhexa(unsigned int nb, int lower);
int		ft_puthexa(unsigned int nb, int lower);
void	init(t_var *var);
int		flagzero(int nb, t_var var, int lower, t_data flags);
int		flagminus2(int nb, t_var var, int lower, t_data flags);
int		flaghashtag(int nb, int count, int lower);

int		do_int(int nb, t_data flags);
int		adjust_int(char *number, int save, t_data flags);
int		do_special(char *number, int save, t_data flags);
int		monmoins(int nb, t_data flags, int count);
int		monpoint(t_data flags, int count);
int		monplus(int nb, t_data flags, int count);

int		do_pointer(unsigned long long nb, t_data flags);
int		adjust_ptr(char *ptr, t_data flags);
char	*ullbase(unsigned long long nb, int base);
char	*write_tab(unsigned long long save, int base, char *tab, int i);
char	*ft_str_tolower(char *str);
int		ft_tolower(int c);

int		do_string(char *str, t_data flags);
int		adjust(char *str, t_data flags);
int		do_precision(char *str, int precision);

int		do_unsignedint(unsigned int nb, t_data flags);
char	*ft_u_itoa(unsigned int n);
char	*ft_putintab(char *number, long nbr, int len, int sign);
int		ft_uintlen(long n);
int		adjust_uint(char *number, t_data flags);
int		do_special2(char *number, t_data flags);

int		do_percent(t_data flags);

int		ft_isflag(char c);
int		ft_isnumber(char c);
int		ft_iscspdiuxx(char c);

int		ft_putnbr(int n);
int		ft_intlen(long n);
char	*ft_strdup(char *src);
size_t	ft_strlen(char const *str);
int		ft_putchar(char c);
char	*ft_itoa(int n);
char	*ft_putintab2(char *number, long nbr, int len, int sign);

#endif
