/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:28:48 by epalomak          #+#    #+#             */
/*   Updated: 2020/09/22 16:24:26 by epalomak         ###   ########.fr       */
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

int				my_abs(int x)
{
	if (x >= 0)
		return (x * 1);
	else
		return (x * -1);
}

void			draw_pixel(t_fdf *map, int x0, int y0, int x1, int y1)
{
	map->dx = my_abs(x1 - x0);
	map->dy = -my_abs(y1 - y0);
	map->x_dir = (x0 < x1) ? 1 : -1;
	map->y_dir = (y0 < y1) ? 1 : -1;
	map->err = map->dx + map->dy;
	while (1)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x0 + map->view_x, y0
				+ map->view_y, map->color);
		if (x0 == x1 && y0 == y1)
			break ;
		map->err_temp = 2 * map->err;
		if (map->err_temp >= map->dy)
		{
			map->err += map->dy;
			x0 += map->x_dir;
		}
		if (map->err_temp <= map->dx)
		{
			map->err += map->dx;
			y0 += map->y_dir;
		}
	}
}

static	void	line(int x0, int y0, int x1, int y1, t_fdf *map)
{
	map->z0 = map->coordinates[y0][x0] * map->altitude;
	map->z1 = map->coordinates[y1][x1] * map->altitude;
	map->x0 = x0 * map->zoom;
	map->x1 = x1 * map->zoom;
	map->y0 = y0 * map->zoom;
	map->y1 = y1 * map->zoom;
	if (map->pers == 'i')
		isometric(map);
	x0 = map->x0;
	y0 = map->y0;
	x1 = map->x1;
	y1 = map->y1;
	draw_pixel(map, x0, y0, x1, y1);
}

void			draw_map(t_fdf *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->max_w)
	{
		x = 0;
		while (x < map->max_l)
		{
			if (x < map->max_l - 1)
				line(x, y, x + 1, y, map);
			if (y < map->max_w - 1)
				line(x, y, x, y + 1, map);
			x++;
		}
		y++;
	}
}
