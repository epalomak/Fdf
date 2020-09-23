/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:28:52 by epalomak          #+#    #+#             */
/*   Updated: 2020/09/23 17:16:38 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		get_altitude(int keycode, t_fdf *map)
{
	if (keycode == 19)
	{
		map->altitude += 1;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		draw_map(map);
	}
	if (keycode == 18)
	{
		map->altitude -= 1;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		draw_map(map);
	}
}

static void		get_color(int keycode, t_fdf *map)
{
	if (keycode == 8)
	{
		if (map->color == 0xFF8000)
			map->color = 0xff0000;
		else if (map->color == 0xff0000)
			map->color = 0x0000ff;
		else if (map->color == 0x0000ff)
			map->color = 0x009933;
		else if (map->color == 0x009933)
			map->color = 0x990099;
		else if (map->color == 0x990099)
			map->color = 0xFF8000;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		draw_map(map);
	}
}

static void		get_move(int keycode, t_fdf *map)
{
	if (keycode == 126)
	{
		map->view_y -= 20;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		draw_map(map);
	}
	if (keycode == 125)
	{
		map->view_y += 20;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		draw_map(map);
	}
	if (keycode == 123)
	{
		map->view_x -= 20;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		draw_map(map);
	}
	if (keycode == 124)
	{
		map->view_x += 20;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		draw_map(map);
	}
}

static void		get_zoom(int keycode, t_fdf *map)
{
	if (keycode == 27)
	{
		if (map->zoom > 1)
		{
			map->zoom = map->zoom / 2;
			mlx_clear_window(map->mlx_ptr, map->win_ptr);
			draw_map(map);
		}
	}
	if (keycode == 24)
	{
		if (map->zoom <= 400)
		{
			map->zoom = map->zoom * 2;
			mlx_clear_window(map->mlx_ptr, map->win_ptr);
			draw_map(map);
		}
	}
}

int				get_events(int keycode, t_fdf *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(1);
	}
	if (keycode == 35)
	{
		map->pers = 'p';
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		draw_map(map);
		
	}
	if (keycode == 34)
	{
		map->pers = 'i';
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		draw_map(map);
		
	}
	get_zoom(keycode, map);
	get_move(keycode, map);
	get_color(keycode, map);
	get_altitude(keycode, map);
	return (0);
}
