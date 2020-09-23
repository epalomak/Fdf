# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/20 03:38:23 by epalomak          #+#    #+#              #
#    Updated: 2020/09/23 17:49:12 by epalomak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FDF = fdf.a

SRC = read.c main.c draw.c manage_keys.c helper.c

OBJ = read.o main.o draw.o manage_keys.o helper.o

INC = fdf.h

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

all: $(NAME)

 $(NAME):
	make -C libft
	@cp $(LIBFT) $(FDF)
	@gcc -c $(FLAGS) $(SRC)
	@ar rc $(FDF) $(OBJ) $(INC)
	gcc $(FDF)  -L /usr/local/lib -lmlx  -framework OpenGL -framework Appkit -o $(NAME)
	@/bin/rm -f $(FDF)

clean:
	@make -C libft clean
	@/bin/rm -f *.o

fclean: clean
	@make -C libft fclean
	@/bin/rm -f $(NAME) $(FDF)

re: fclean all
