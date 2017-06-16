# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kzeng <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/07 00:06:43 by kzeng             #+#    #+#              #
#    Updated: 2017/02/07 00:06:44 by kzeng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpushswap.a
CC = gcc
FLAG = -c -Wall -Wextra -Werror
SRC = ft_push_find.c \
		ft_push_find2.c \
		ft_push_handle_500.c \
		ft_push_helper.c \
		ft_push_helper2.c \
		ft_push_helper3.c \
		ft_push_input_check.c \
		ft_push_printf.c \
		ft_push_right.c \
		ft_push_swap.c \
		ft_swap_op.c \
		ft_swap_op2.c \
		ft_swap_op3.c \

OBJ = $(SRC:.c=.o)

INC = -I pushswap.h
AR = ar rc
RM = rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	$(CC) $(FLAG) $(SRC) $(INC)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
