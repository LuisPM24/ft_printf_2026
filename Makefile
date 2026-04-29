# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/28 09:54:53 by lupalomi          #+#    #+#              #
#    Updated: 2026/04/28 18:45:21 by lupalomi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c \
       printf_text_functions.c \
       printf_putvoid.c \
       printf_putnbr.c \
       printf_putunnbr.c \
	   printf_puthex.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

.PHONY: all bonus clean fclean re
