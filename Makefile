NAME = fdf

all: $(NAME)


 $(NAME):
	make -C libft
	gcc main.c -L /usr/local/lib -lmlx -I /usr/local/X11/include -L/usr/X11/lib -lX11 -lXext -framework OpenGL -framework Appkit -o $(NAME)

clean:
	@/bin/rm -f $(NAME)

re: clean all
