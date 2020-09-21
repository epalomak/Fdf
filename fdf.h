/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 12:19:10 by epalomak          #+#    #+#             */
/*   Updated: 2020/09/20 05:25:22 by epalomak         ###   ########.fr       */
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

#define ABS(a) ((a < 0) ? -a : a)
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)

typedef	struct		s_fdf
{ 
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				max_l;
	int				max_w;
	int				**coordinates;
	int				zoom;
	int				color;

	void			*mlx_ptr;
	void			*win_ptr;
	struct s_fdf	*next;
}					t_fdf;

//t_fdf			*get_lenght(t_fdf *map, char **av);
void			draw_map(t_fdf *map);
void		read_file(t_fdf *map, char *av[]);

#endif