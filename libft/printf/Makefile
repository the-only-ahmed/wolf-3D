# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/23 08:43:54 by ael-kadh          #+#    #+#              #
#    Updated: 2014/01/11 04:30:53 by ael-kadh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_itoa.c ft_strdup.c ft_strlen.c \
		ft_printf.c ft_strjoin.c ft_atoi.c ft_uputnbr.c ft_pointer.c\
		ft_uput2long.c ft_point.c ft_isascii.c ft_printf_2.c ft_printf_3.c\
		floats.c
HEAD = ./includes/
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
		@gcc $(FLAGS) -I $(HEAD) -c $(SRC)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

clean :
		@rm -f $(OBJ)

fclean : clean
		@rm -f $(NAME)

re : fclean all
