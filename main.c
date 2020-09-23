/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:23:53 by epalomak          #+#    #+#             */
/*   Updated: 2020/09/23 15:21:05 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		set_map_rules(t_fdf *map)
{
	map->zoom = 20;
	map->view_x = 700;
	map->view_y = 400;
	map->pers = 'i';
	map->altitude = 1;
	map->color = 0xFF8000;
}

int				main(int ac, char **av)
{
	t_fdf *map;

	if (!(map = (t_fdf*)malloc(sizeof(t_fdf))))
		return (0);
	if (ac == 2)
	{
		set_map_rules(map);
		create_map_array(map, av);
		map->mlx_ptr = mlx_init();
		map->win_ptr = mlx_new_window(map->mlx_ptr, 1600, 1200, av[1]);
		draw_map(map);
		mlx_key_hook(map->win_ptr, get_events, map);
		mlx_loop(map->mlx_ptr);
	}
	free(map);
	return (0);
}
