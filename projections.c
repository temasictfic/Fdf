/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 04:46:40 by sciftci           #+#    #+#             */
/*   Updated: 2022/12/29 20:18:24 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_p *p1, t_p *p2, t_z *z, double x_angle)
{
	int	prev_y1;
	int	prev_y2;

	prev_y1 = p1->y;
	prev_y2 = p2->y;
	p1->y = prev_y1 * cos(x_angle) + z->z1 * sin(x_angle);
	z->z1 = -prev_y1 * sin(x_angle) + z->z1 * cos(x_angle);
	p2->y = prev_y2 * cos(x_angle) + z->z2 * sin(x_angle);
	z->z2 = -prev_y2 * sin(x_angle) + z->z2 * cos(x_angle);
}

void	rotate_y(t_p *p1, t_p *p2, t_z *z, double y_angle)
{
	int	prev_x1;
	int	prev_x2;

	prev_x1 = p1->x;
	prev_x2 = p2->x;
	p1->x = prev_x1 * cos(y_angle) + z->z1 * sin(y_angle);
	z->z1 = -prev_x1 * sin(y_angle) + z->z1 * cos(y_angle);
	p2->x = prev_x2 * cos(y_angle) + z->z2 * sin(y_angle);
	z->z2 = -prev_x2 * sin(y_angle) + z->z2 * cos(y_angle);
}

void	rotate_z(t_p *p1, t_p *p2, t_z *z, double z_angle)
{
	int	prev_x1;
	int	prev_x2;
	int	prev_y1;
	int	prev_y2;

	(void)z;
	prev_x1 = p1->x;
	prev_y1 = p1->y;
	prev_x2 = p2->x;
	prev_y2 = p2->y;
	p1->x = prev_x1 * cos(z_angle) - prev_y1 * sin(z_angle);
	p1->y = prev_x1 * sin(z_angle) + prev_y1 * cos(z_angle);
	p2->x = prev_x2 * cos(z_angle) - prev_y2 * sin(z_angle);
	p2->y = prev_x2 * sin(z_angle) + prev_y2 * cos(z_angle);
}

void	iso(t_p *p, int z, t_mlx *mlx)
{
	(void)mlx;
	p->x = (p->x - p->y) * cos(M_PI * 30 / 180);
	p->y = -z + (p->x + p->y) * sin(M_PI * 30 / 180);
}

void	apply_iso(t_p *p1, t_p *p2, t_z *z, t_mlx *mlx)
{
	iso(p1, z->z1, mlx);
	iso(p2, z->z2, mlx);
}
