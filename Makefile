# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/07 21:28:19 by ael-kadh          #+#    #+#              #
#    Updated: 2014/01/18 22:29:43 by ael-kadh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Wolf3D
SRC = get_next_line.c main.c event.c draw.c ray.c mini.c bres.c reading.c\
		menu.c int_draw.c initialisation.c loading.c saving.c texture.c floor.c\
		ft_main.c event_mouse.c init.c sprites.c parse_o.c comb_sort.c\
		filling_text.c
HEAD = wolf.h get_next_line.h lists.h
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror -g3

all : $(NAME)


$(NAME) :
	@make -C libft
	@gcc $(FLAGS) -I libft/includes -I /usr/X11/include -I /usr/include\
					-I libft/printf/includes -c $(SRC)
	@gcc $(OBJ) -L libft -lft -L/usr/X11/lib -lmlx -lXext -lX11\
					libft/printf/libftprintf.a -o $(NAME)

clean :
	@make -C libft clean
	@rm -f $(OBJ)

fclean : clean
	@make -C libft fclean
	@rm -f $(NAME)

re : fclean all
