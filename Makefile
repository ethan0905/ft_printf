# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esafar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 11:13:31 by esafar            #+#    #+#              #
#    Updated: 2021/09/22 14:29:23 by esafar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
		ft_printf2.c \
		srcs/do_percent.c \
		srcs/do_char.c \
		srcs/do_hexa1.c \
		srcs/do_hexa2.c \
		srcs/do_int1.c \
		srcs/do_int2.c \
		srcs/do_pointer1.c \
		srcs/do_pointer2.c \
		srcs/do_string.c \
		srcs/do_uint1.c \
		srcs/do_uint2.c \
		srcs/ft_check.c \
		srcs/ft_utils1.c \
		srcs/ft_utils2.c

SRCS_B = ft_printf.c \
		ft_printf2.c \
		srcs/do_percent.c \
		srcs/do_char.c \
		srcs/do_hexa1.c \
		srcs/do_hexa2.c \
		srcs/do_int1.c \
		srcs/do_int2.c \
		srcs/do_pointer1.c \
		srcs/do_pointer2.c \
		srcs/do_string.c \
		srcs/do_uint1.c \
		srcs/do_uint2.c \
		srcs/ft_check.c \
		srcs/ft_utils1.c \
		srcs/ft_utils2.c

OBJS = ${SRCS:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}

#HEADER = ./includes/

CFLAGS = -Wall -Wextra -Werror

all:	${NAME}

.c.o:
	gcc ${CFLAGS} -c $< -o ${<:.c=.o} #-I ${HEADER}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

bonus: ${OBJS} ${OBJS_B}
	ar rcs ${NAME} ${OBJS} ${OBJS_B}

clean:
	rm -f ${OBJS} ${OBJS_B}

fclean:	clean
	rm -f ${NAME} bonus

re:	fclean all
