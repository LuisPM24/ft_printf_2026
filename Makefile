# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/28 09:54:53 by lupalomi          #+#    #+#              #
#    Updated: 2026/05/04 23:40:15 by lupalomi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

DIR = src
BONUS_DIR = src_bonus

SRCS = $(DIR)/ft_printf.c \
       $(DIR)/printf_text_functions.c \
       $(DIR)/printf_putvoid.c \
       $(DIR)/printf_putnbr.c \
       $(DIR)/printf_putunnbr.c \
	   $(DIR)/printf_puthex.c
BONUS_SRCS =	$(BONUS_DIR)/ft_printf_bonus.c \
				$(BONUS_DIR)/manage_width_bonus.c \
				$(BONUS_DIR)/start_parser_bonus.c \
				$(BONUS_DIR)/parser_bonus.c \
				$(BONUS_DIR)/printf_putstr_bonus.c \
				$(BONUS_DIR)/printf_putvoid_bonus.c \
				$(BONUS_DIR)/printf_putnbr_bonus.c \
				$(BONUS_DIR)/printf_putunnbr_bonus.c \
				$(BONUS_DIR)/printf_puthex_bonus.c \
				$(BONUS_DIR)/auxiliar_functions_bonus.c

MANDATORY_SENTINEL = $(DIR)/.mandatory
BONUS_SENTINEL = $(BONUS_DIR)/.bonus

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MANDATORY_SENTINEL)
	rm -rf $(NAME)
	ar rcs $(NAME) $(OBJS)

$(MANDATORY_SENTINEL): $(OBJS)
	rm -rf $(NAME)
	rm -rf $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS)
	rm -rf $(BONUS_SENTINEL)
	touch $(MANDATORY_SENTINEL)

bonus: $(BONUS_SENTINEL)

$(BONUS_SENTINEL): $(BONUS_OBJS)
	rm -rf $(NAME)
	rm -rf $(OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)
	rm -rf $(MANDATORY_SENTINEL)
	touch $(BONUS_SENTINEL)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(MANDATORY_SENTINEL)
	rm -rf $(BONUS_SENTINEL)

re: fclean all

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

.PHONY: all bonus clean fclean re
