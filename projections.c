/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 04:46:40 by sciftci           #+#    #+#             */
/*   Updated: 2022/12/14 04:46:29 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	side(t_p *p, int z, t_mlx *mlx)
{
	p->x = p->x * sin(mlx->angle);
	p->y = z * mlx->raise_z - p->x * cos(mlx->angle);
}

void	apply_side(t_p *p1, t_p *p2, t_z *z, t_mlx *mlx)
{
	side(p1, z->z1, mlx);
	side(p2, z->z2, mlx);
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
