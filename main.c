/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:23:53 by epalomak          #+#    #+#             */
/*   Updated: 2020/09/20 05:29:32 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int deal_key(int key, t_fdf *map)
{
	if (key == 53)
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	return (0);
}

int		main(int ac, char **av)
{	
	t_fdf *map;

	if (!(map = (t_fdf*)malloc(sizeof(t_fdf))))
		return (0);
	if (ac == 2)
	{
		read_file(map, av);
		map->zoom = 20;
		map->mlx_ptr = mlx_init();
		map->win_ptr = mlx_new_window(map->mlx_ptr, 950, 950, av[1]);
		draw_map(map);
		printf("yo, yo, yo is it working\n");
		mlx_key_hook(map->win_ptr, deal_key, map);
		mlx_loop(map->mlx_ptr);
	}
	free(map);
	return (0);
}

