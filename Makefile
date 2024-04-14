# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 19:12:30 by madamou           #+#    #+#              #
#    Updated: 2024/04/14 03:00:45 by madamou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_itoa.c functions.c functions2.c functions3.c \
		functions4.c functions5.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all = $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c -include ./ft_printf.h $< -o $@

bonus : all

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus