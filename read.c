/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 15:19:02 by epalomak          #+#    #+#             */
/*   Updated: 2020/09/22 16:20:20 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fill_base_map(t_fdf *map, int i, char **src)
{
	int j;

	j = 0;
	while (j < map->max_l)
	{
		map->coordinates[i][j] = ft_atoi(src[j]);
		free(src[j]);
		j++;
	}
	free(src[j]);
	free(src);
}

static void		map_base(t_fdf *map, char **av)
{
	int		fd;
	char	*line;
	char	**src;
	int		i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (!(map->coordinates = (int **)malloc(map->max_w * sizeof(int *))))
		exit(0);
	while (get_next_line(fd, &line) > 0)
	{
		src = ft_strsplit(line, ' ');
		free(line);
		map->coordinates[i] = (int *)malloc(map->max_l * sizeof(int));
		fill_base_map(map, i, src);
		i++;
	}
	close(fd);
}

static void		get_width(t_fdf *map, char **av)
{
	int		fd;
	char	*line;

	map->max_w = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		map->max_w++;
		free(line);
	}
	close(fd);
}

static void		get_lenght(t_fdf *map, char **av)
{
	int		fd;
	int		i;
	char	*line;
	char	**src;

	i = 0;
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	src = ft_strsplit(line, ' ');
	free(line);
	while (src[i] != NULL)
	{
		free(src[i]);
		i++;
	}
	free(src[i]);
	free(src);
	map->max_l = i;
	close(fd);
}

void			create_map_array(t_fdf *map, char **av)
{
	get_lenght(map, av);
	get_width(map, av);
	map_base(map, av);
}
