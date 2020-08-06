/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 12:17:35 by epalomak          #+#    #+#             */
/*   Updated: 2020/07/13 10:54:34 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		do_line(void *mlx, void *win, int x1, int y1, int x2, int y2, int clr)
{
	double	dx;
	double	dy;
	double	pxlx;
	double	pxly;
	int		pxl;

	dx = x2 - x1;
	dy = y2 - y1;
	pxl = sqrt(dx * dx) + sqrt(dy * dy);
	dx /= pxl;
	dy /= pxl;
	pxlx = x1;
	pxly = y1;
	while (pxl)
	{
		mlx_pixel_put(mlx, win, pxlx, pxly, clr);
    	pxlx += dx;
    	pxly += dy;
    	--pxl;
	}
	return (0);
}

int		do_square(void *mlx, void *win, int x1, int y1, int wd, int sqrw,  int clr)
{
	int sides;
	int countx;
	int county;
	int tempx;

	countx = wd + x1;
	county = wd / sqrw;
	tempx = x1;
	do_line (mlx, win, x1, y1, x1 + wd , y1, 0xFF8000);
	do_line (mlx, win, x1, y1, x1 , y1 + wd, 0xFF8000);
	do_line (mlx, win, x1 + wd, y1, x1 + wd , y1 + wd, 0xFF8000);
	do_line (mlx, win, x1, y1 + wd, x1 + wd , y1 + wd, 0xFF8000);
	
	while(county)
	{
		x1 = tempx;
		while ( countx > x1)
		{
			do_line (mlx, win, x1, y1, x1 + sqrw , y1, 0xFF8000);
			do_line (mlx, win, x1, y1, x1 , y1 + sqrw, 0xFF8000);
			do_line (mlx, win, x1 + sqrw, y1, x1 + sqrw , y1 + sqrw, 0xFF8000);
			do_line (mlx, win, x1, y1 + sqrw, x1 + sqrw , y1 + sqrw, 0xFF8000);
			x1 += sqrw;
		}
		county -= 1;
		y1 += sqrw;
	}
	return (0);
}

int     main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	void 	*img;
	int		x1;
	int		y1;
	int		x2;
	int		y2;

	x1 = 100;
	y1 = 100;
	x2 = 500;
	y2 = 100;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "testing");
	do_square(mlx, win, x1, y1, 200, 10, 0xFF8000);
	mlx_loop(mlx);
}
