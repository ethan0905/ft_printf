# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esafar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 11:13:31 by esafar            #+#    #+#              #
#    Updated: 2021/09/19 12:30:12 by esafar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c / ft_printf2.c / srcs/do_percent.c / srcs/do_char.c / srcs/do_hexa1.c / srcs/do_hexa2.c / srcs/do_int1.c / srcs/do_int2.c / srcs/do_pointer1.c / srcs/do_pointer2.c / srcs/do_string.c / srcs/do_uint1.c / srcs/do_uint2.c / srcs/ft_check.c / srcs/ft_utils1.c / srcs/ft_utils2.c


OBJS = ${SRCS:.c=.o}

HEADER = ./includes/

CFLAGS = -Wall -Wextra -Werror

all:	${NAME}

.c.o:
	gcc ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADER}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all
