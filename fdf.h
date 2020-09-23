/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 12:19:10 by epalomak          #+#    #+#             */
/*   Updated: 2020/09/23 15:08:39 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef	struct		s_data
{
	int				x0;
	int				x1;
	int				y0;
	int				y1;
}					t_data;

typedef	struct		s_fdf
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				z0;
	int				z1;
	int				deltax;
	int				deltay;
	int				x_direc;
	int				y_direc;
	int				view_y;
	int				view_x;
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

void				create_map_array(t_fdf *map, char **av);
void				draw_map(t_fdf *map);
void				read_file(t_fdf *map, char *av[]);
int					get_events(int keycode, t_fdf *map);
int					my_abs(int x);

#endif
