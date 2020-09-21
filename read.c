/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 15:19:02 by epalomak          #+#    #+#             */
/*   Updated: 2020/09/20 05:24:43 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
static void	fill_base_map(t_fdf *map, int i, char **src)
{
	int j;

	j = 0;
	while (j < map->max_l)
	{
		map->coordinates[i][j] = ft_atoi(src[j]);
		j++;
	}
}

static t_fdf	*map_base(t_fdf *map, char **av)
{
	int		fd;
	char	*line;
	char	**src;
	int		i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (!(map->coordinates = (int **)malloc(map->max_w * sizeof(int *))))
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		src = ft_strsplit(line, ' ');
		map->coordinates[i] = (int *)malloc(map->max_l * sizeof(int));
		fill_base_map(map, i, src);
		free(line);
		i++;
	}
	close(fd);
	return(map);
}

static t_fdf	*get_width(t_fdf *map, char **av)
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
	return (map_base(map, av));
}

static void	clear_array(int ac, char **ar)
{
	int i;

	i = 0;
	while (i < ac)
	{
		free(ar[i]);
		i++;
	}
	free(ar);
}

t_fdf			*get_lenght(t_fdf *map, char **av)
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
		i++;
	map->max_l = i;
	clear_array(i, src);
	close(fd);
	return (get_width(map, av));
}*/

#include "fdf.h"

static void	fill_coordinates_i(t_fdf *map, int i, char **rcp)
{
	int j;

	j = 0;
	while (j < map->max_l)
	{
		map->coordinates[i][j] = ft_atoi(rcp[j]);
		j++;
	}
}

static void	create_coordinates(t_fdf *map, char *av[])
{
	int		fd;
	char	*line;
	char	**rcp;
	int		i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	map->coordinates = (int **)malloc(map->max_w * sizeof(int *));
	while (get_next_line(fd, &line) > 0)
	{
		rcp = ft_strsplit(line, ' ');
		map->coordinates[i] = (int *)malloc(map->max_l * sizeof(int));
		fill_coordinates_i(map, i, rcp);
		free(line);
		i++;
	}
	close(fd);
}

static void	count_width(t_fdf *map, char *av[])
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
	}
	map->max_w = i;
	close(fd);
}

static void	clear_array(int ac, char **ar)
{
	int i;

	i = 0;
	while (i < ac)
	{
		free(ar[i]);
		i++;
	}
	free(ar);
}

static void	count_length(t_fdf *map, char *av[])
{
	int		fd;
	char	*line;
	char	**rcp;
	int		i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	rcp = ft_strsplit(line, ' ');
	free(line);
	while (rcp[i] != NULL)
		i++;
	map->max_l = i;
	clear_array(i, rcp);
	close(fd);
}

void		read_file(t_fdf *map, char *av[])
{
	count_length(map, av);
	count_width(map, av);
	create_coordinates(map, av);
}
