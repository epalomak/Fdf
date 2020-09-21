/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:28:48 by epalomak          #+#    #+#             */
/*   Updated: 2020/09/20 05:27:27 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void isomitric(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	line(int x0, int y0, int x1, int y1, t_fdf *map)
{
	int deltax;
	int deltay;
	int error;
	int deltaerr;
	int diry;
	int z0;
	int z1;

	z0 = map->coordinates[y0][x0];
	z1 = map->coordinates[y1][x1];
	isomitric(&x0, &y0, z0);
	isomitric(&x1, &y1, z1);

	deltax = x1 - x0;
	deltay = y1 - y0;
	error = 0;
	deltaerr = (MIN(deltax, deltay) + 1) / (MAX(deltax, deltay) + 1);
	diry = MIN(deltax, deltay);
	diry = (diry > 0) ? 1 : -1;

	while ((x0 < x1) || y0 < y1)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x0, y0, 0xFF800);
		error = error + deltaerr;
		if (deltay < deltax)
		{
			if (error >= 1)
			{
				y0 = y0 + diry;
				error = error - 1.0;
			}
			x0++;
		}
		else
		{
			if (error >= 1)
			{
				x0 = x0 + diry;
				error = error - 1.0;
			}
			y0++;
		}
	}
}

void	draw_map(t_fdf *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->max_w)
	{
		x = 0;
		while (x < map->max_l)
		{
			if (x < map->max_l- 1)
				line(x, y, x + 1, y, map);
			if (y < map->max_w - 1)
				line(x, y, x, y + 1, map);
			x++;
		}
		y++;
	}
}