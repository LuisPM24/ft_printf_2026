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
BONUS_SRCS =	ft_printf_bonus.c \
				manage_width_bonus.c \
				start_parser_bonus.c \
				parser_bonus.c \
		        printf_text_functions.c \
				printf_putstr_bonus.c \
				printf_putvoid_bonus.c \
				printf_putnbr_bonus.c \
				printf_putunnbr_bonus.c \
				printf_puthex_bonus.c \
				printf_putper_bonus.c \
				auxiliar_functions_bonus.c


OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

.PHONY: all bonus clean fclean re
