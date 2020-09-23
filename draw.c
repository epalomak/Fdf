/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:28:48 by epalomak          #+#    #+#             */
/*   Updated: 2020/09/23 16:56:57 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			isometric(t_fdf *map)
{
	int	prev_x;
	int	prev_y;

	prev_x = map->x0;
	prev_y = map->y0;
	map->x0 = (prev_x - prev_y) * cos(0.523599);
	map->y0 = -(map->z0) + (prev_x + prev_y) * sin(0.523599);
	prev_x = map->x1;
	prev_y = map->y1;
	map->x1 = (prev_x - prev_y) * cos(0.523599);
	map->y1 = -(map->z1) + (prev_x + prev_y) * sin(0.523599);
}

void			draw(t_fdf *map, t_data final)
{
	map->deltax = my_abs(final.x1 - final.x0);
	map->deltay = -my_abs(final.y1 - final.y0);
	map->x_direc = (final.x0 < final.x1) ? 1 : -1;
	map->y_direc = (final.y0 < final.y1) ? 1 : -1;
	map->err = map->deltax + map->deltay;
	while (1)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, final.x0 + map->view_x,
		final.y0 + map->view_y, map->color);
		if (final.x0 == final.x1 && final.y0 == final.y1)
			break ;
		map->err_temp = 2 * map->err;
		if (map->err_temp >= map->deltay)
		{
			map->err += map->deltay;
			final.x0 += map->x_direc;
		}
		if (map->err_temp <= map->deltax)
		{
			map->err += map->deltax;
			final.y0 += map->y_direc;
		}
	}
}

static	void	correct_coords(t_fdf *map, t_data final)
{
	map->z0 = map->coordinates[final.y0][final.x0] * map->altitude;
	map->z1 = map->coordinates[final.y1][final.x1] * map->altitude;
	map->x0 = final.x0 * map->zoom;
	map->x1 = final.x1 * map->zoom;
	map->y0 = final.y0 * map->zoom;
	map->y1 = final.y1 * map->zoom;
	if (map->pers == 'i')
		isometric(map);
	final.x0 = map->x0;
	final.y0 = map->y0;
	final.x1 = map->x1;
	final.y1 = map->y1;
	draw(map, final);
}

static	void	start(t_fdf *map, int x, int y)
{
	t_data	final;

	final.x0 = x;
	final.y0 = y;
	if (x < map->max_l - 1)
	{
		final.y1 = y;
		final.x1 = x + 1;
		correct_coords(map, final);
	}
	if (y < map->max_w - 1)
	{
		final.x1 = x;
		final.y1 = y + 1;
		correct_coords(map, final);
	}
}

void			draw_map(t_fdf *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->max_w)
	{
		x = 0;
		while (x < map->max_l)
		{
			start(map, x, y);
			x++;
		}
		y++;
	}
}
