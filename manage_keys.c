/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:28:52 by epalomak          #+#    #+#             */
/*   Updated: 2020/09/22 12:54:00 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_zoom(int keycode, t_fdf *map)
{
	if (keycode == 125)
	{
		if (map->zoom > 1)
		{
			map->zoom = map->zoom / 2;
			map->zoom = map->zoom / 2;
			mlx_clear_window(map->mlx_ptr, map->win_ptr);
			draw_map(map);
		}
	}
	if (keycode == 126)
	{
		if (map->zoom <= 400)
		{
			map->zoom = map->zoom * 2;
			map->zoom = map->zoom * 2;
			mlx_clear_window(map->mlx_ptr, map->win_ptr);
			draw_map(map);
		}
	}
	return (0);
}

int		get_events(int keycode, t_fdf *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit (1);
	}
	get_zoom(keycode, map);
	return (0);
}