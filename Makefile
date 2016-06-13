# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/11 12:15:05 by jdhaisne          #+#    #+#              #
#    Updated: 2016/05/11 12:27:27 by jdhaisne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_select

SRC = ft_select.c \
	  d_list.c \
	  init.c \
	  move.c \
	  show_menu.c \
	  quit.c \
	  create_str.c \
	  signal.c \
	  gnl/get_next_line.c \

OBJ = ft_select.o \
	  d_list.o \
	  init.o \
	  move.o \
	  show_menu.o \
	  quit.o \
	  create_str.o \
	  signal.o \
	  get_next_line.o \

LIB = libft.a -ltermcap

CFLAG = -Wall -Werror -Wextra

LIBFT_DIR = libft

all : $(NAME)

$(NAME) :
	make -C $(LIBFT_DIR) re
	gcc -c $(SRC) $(CFLAG)
	gcc -o $(NAME) $(OBJ) $(LIBFT_DIR)/$(LIB)

.PHONY:clean
clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
