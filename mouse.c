/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 04:46:24 by sciftci           #+#    #+#             */
/*   Updated: 2022/12/06 09:43:57 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse(int keycode, int x, int y, void *param)
{
	t_mlx	*mlx;

	(void)x;
	(void)y;
	mlx = (t_mlx *)param;
	if (keycode == MOUSE_SCROLLDOWN)
		mlx->map->zoom -= 1;
	else if (keycode == MOUSE_SCROLLUP)
		mlx->map->zoom += 1;
	else if (keycode == MOUSE_LEFT)
	{
		mlx->mouse->x = x;
		mlx->mouse->y = y;
		mlx->onclick = 1;
	}
	draw(mlx);
	return (0);
}

int	mouse_release(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	(void)x;
	(void)y;
	(void)button;
	mlx->onclick = 0;
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	t_mlx	*mlx;
	int		prev_x;
	int		prev_y;

	mlx = (t_mlx *)param;
	if (!mlx->onclick)
		return (0);
	prev_x = mlx->mouse->x;
	prev_y = mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	mlx->offset_x += x - prev_x;
	mlx->offset_y += y - prev_y;
	draw(mlx);
	return (0);
}
