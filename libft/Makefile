# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/23 08:43:54 by ael-kadh          #+#    #+#              #
#    Updated: 2014/01/18 00:35:40 by ael-kadh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
		ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
		ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c ft_strcmp.c\
		ft_strcpy.c ft_strlcat.c ft_strlen.c ft_strncat.c ft_strsub.c\
		ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c\
		ft_toupper.c ft_tolower.c ft_isdigit.c ft_lstmap.c ft_lstiter.c\
		ft_lstadd.c ft_lstnew.c ft_lstdel.c ft_memalloc.c ft_strtrim.c\
		ft_memdel.c ft_putchar_fd.c ft_putendl.c math.c sinus.c\
		ft_putendl_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_strclr.c\
		ft_strdel.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c\
		ft_strmap.c ft_strmapi.c ft_strnequ.c ft_strnew.c ft_strsplit.c
HEAD = ./includes/
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	@make -C printf
	@gcc $(FLAGS) -I $(HEAD) -I printf/includes -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean :
	@make -C printf clean
	@rm -f $(OBJ)

fclean : clean
	@make -C printf fclean
	@rm -f $(NAME) ./includes/libft.h.gch

re : fclean all
