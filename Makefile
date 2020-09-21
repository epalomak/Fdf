# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/20 03:38:23 by epalomak          #+#    #+#              #
#    Updated: 2020/09/20 04:20:36 by epalomak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = read.c main.c draw.c

all: $(NAME)


 $(NAME):
	make -C libft
	gcc libft/libft.a $(SRC) -L /usr/local/lib -lmlx -I /usr/local/X11/include -L/usr/X11/lib -lX11 -lXext -framework OpenGL -framework Appkit -o $(NAME)

clean:
	@/bin/rm -f $(NAME)

re: clean all
