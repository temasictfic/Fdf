/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 04:46:40 by sciftci           #+#    #+#             */
/*   Updated: 2022/12/06 04:46:46 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	conic(t_p *p, int z, t_mlx *mlx)
{
	p->x = (p->x - p->y) * tan(mlx->angle);
	p->y = (-z * mlx->raise_z) + (p->x + p->y) * tan(mlx->angle);
}

void	apply_conic(t_p *p1, t_p *p2, t_z *z, t_mlx *mlx)
{
	conic(p1, z->z1, mlx);
	conic(p2, z->z2, mlx);
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
