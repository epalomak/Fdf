/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 12:19:10 by epalomak          #+#    #+#             */
/*   Updated: 2020/09/22 16:01:37 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef	struct		s_fdf
{ 
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				z0;
	int				z1;
	int				dx;
	int				dy;
	int				x_dir;
	int				y_dir;
	int				view_y;
	int 			view_x;
	int				altitude;
	int				max_l;
	int				max_w;
	int				**coordinates;
	int				err_temp;
	int				err;
	int				zoom;
	char			pers;
	unsigned long	color;

	void			*mlx_ptr;
	void			*win_ptr;
	struct s_fdf	*next;
}					t_fdf;

void			create_map_array(t_fdf *map, char **av);
void			draw_map(t_fdf *map);
void			read_file(t_fdf *map, char *av[]);
int				get_events(int keycode, t_fdf *map);

#endif