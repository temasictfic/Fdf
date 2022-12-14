/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 04:42:43 by sciftci           #+#    #+#             */
/*   Updated: 2022/12/14 04:52:48 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color(int z, int z2, t_map *map)
{
	int	d;

	if (z2 > z)
		d = z2;
	else
		d = z;
	map->color = 0;
	if (d <= 0)
		map->color = 0x3264B8;
	else if (d > 0 && d <= 10)
		map->color = 0x32B864;
	else if (d > 10 && d <= 20)
		map->color = 0x96C896;
	else if (d > 20 && d <= 50)
		map->color = 0xFAFAC8;
	else if (z > 50 && z <= 70)
		map->color = 0x966450;
	else if (d > 70)
		map->color = 0xEFEFEF;
	return (map->color);
}

void	zoom(t_p *p1, t_p *p2, t_mlx *mlx)
{
	p1->x = (p1->x - (mlx->map->width / 2)) * mlx->map->zoom;
	p2->x = (p2->x - (mlx->map->width / 2)) * mlx->map->zoom;
	p1->y = (p1->y - (mlx->map->height / 2)) * mlx->map->zoom;
	p2->y = (p2->y - (mlx->map->height / 2)) * mlx->map->zoom;
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;
	int		x_calc;
	int		y_calc;

	x_calc = x + mlx->offset_x;
	y_calc = y + mlx->offset_y;
	if (x_calc > 0 && y_calc >= 0 && x_calc < WIN_WIDTH && y_calc < WIN_HEIGHT)
	{
		dst = mlx->addr + (y_calc * mlx->line_length + x_calc
				* (mlx->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	init_coordinates(t_p *p1, t_p *p2, t_z *z, t_mlx *mlx)
{
	z->z1 = mlx->map->lines[p1->y][p1->x];
	z->z2 = mlx->map->lines[p2->y][p2->x];
	zoom(p1, p2, mlx);
	if (mlx->projection == 1)
		apply_iso(p1, p2, z, mlx);
	else if (mlx->projection == 2)
		apply_side(p1, p2, z, mlx);
}

void	bresenham(t_p p1, t_p p2, t_mlx *mlx)
{
	t_z	z;
	t_p	delta;
	int	err;
	int	e2;

	init_coordinates(&p1, &p2, &z, mlx);
	delta = point(abs(p1.x - p2.x), abs(p1.y - p2.y));
	err = err_calculation(&delta);
	while (1)
	{
		my_mlx_pixel_put(mlx, p1.x, p1.y, color(z.z1, z.z2, mlx->map));
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		e2 = err;
		if (e2 > -delta.x)
		{
			err -= delta.y;
			p1.x += (p1.x < p2.x) - (p1.x >= p2.x);
		}
		if (e2 < delta.y)
		{
			err += delta.x;
			p1.y += (p1.y < p2.y) - (p1.y >= p2.y);
		}
	}
}
