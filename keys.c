/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 04:44:37 by sciftci           #+#    #+#             */
/*   Updated: 2022/12/06 04:45:19 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	escape(void *param)
{
	(void)param;
	exit(0);
}

void	keyboard_key(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_ARROWUP)
		mlx->offset_y -= 16;
	else if (keycode == KEY_ARROWDOWN)
		mlx->offset_y += 16;
	else if (keycode == KEY_ARROWRIGHT)
		mlx->offset_x += 16;
	else if (keycode == KEY_ARROWLEFT)
		mlx->offset_x -= 16;
	else if (keycode == KEY_I)
		mlx->map->zoom++;
	else if (keycode == KEY_O)
		mlx->map->zoom--;
	else if (keycode == KEY_W)
		mlx->raise_z += 0.1;
	else if (keycode == KEY_S)
		mlx->raise_z -= 0.1;
	else if (keycode == KEY_A)
		mlx->angle += 0.025;
	else if (keycode == KEY_D)
		mlx->angle -= 0.025;
}

void	projection_key(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ONE)
		mlx->projection = 0;
	else if (keycode == KEY_TWO)
		mlx->projection = 1;
	else if (keycode == KEY_THREE)
		mlx->projection = 2;
}

int	deal_key(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	keyboard_key(keycode, mlx);
	projection_key(keycode, mlx);
	draw(mlx);
	return (0);
}

void	setup_controls(t_mlx *mlx)
{
	mlx_hook(mlx->window, EVENT_ON_KEYDOWN, NO_MASK, deal_key, mlx);
	mlx_hook(mlx->window, EVENT_ON_DESTROY, NO_MASK, escape, mlx);
	mlx_hook(mlx->window, EVENT_ON_MOUSEDOWN, NO_MASK, mouse, mlx);
	mlx_hook(mlx->window, EVENT_ON_MOUSEMOVE, NO_MASK, mouse_move, mlx);
	mlx_hook(mlx->window, EVENT_ON_MOUSEUP, NO_MASK, mouse_release, mlx);
	init_img(mlx);
	draw(mlx);
}
