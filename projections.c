/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 04:46:40 by sciftci           #+#    #+#             */
/*   Updated: 2022/12/29 04:43:31 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
static void	side(t_p *p, int z, t_mlx *mlx)
{
	p->x = p->x * sin(mlx->angle);
	p->y = z * mlx->raise_z - p->x * cos(mlx->angle);
}*/
/*
void	apply_side(t_p *p1, t_p *p2, t_z *z, t_mlx *mlx)
{
	side(p1, z->z1, mlx);
	side(p2, z->z2, mlx);
}*/
static void	rotate_x(int *y, int *z, double alpha)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(alpha) + (*z) * sin(alpha);
	*z = -prev_y * sin(alpha) + (*z) * cos(alpha);
}

static void	rotate_y(int *x, int *z, double beta)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(beta) + (*z) * sin(beta);
	*z = -prev_x * sin(beta) + (*z) * cos(beta);
}

static void	rotate_z(int *x, int *y, double gamma)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(gamma) - prev_y * sin(gamma);
	*y = prev_x * sin(gamma) + prev_y * cos(gamma);
}

static void	iso(t_p *p, int z, t_mlx *mlx)
{
	p->x = (p->x - p->y) * cos(mlx->angle);
	p->y = (-z * mlx->raise_z) + (p->x + p->y) * sin(mlx->angle);
}

void	apply_iso(t_p *p1, t_p *p2, t_z *z, t_mlx *mlx)
{
	iso(p1, z->z1, mlx);
	iso(p2, z->z2, mlx);
}
