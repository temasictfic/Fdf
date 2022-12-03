#include "fdf.h"

int	escape(void *param)
{
	(void)param;
	exit (0);
}

void	control_key(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		exit (0);
	else if (keycode == KEY_ARROWDOWN)
		mlx->offset_y -= 16;
	else if (keycode == KEY_ARROWUP)
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
		mlx->raise_z++;
	else if (keycode == KEY_S)
		mlx->raise_z--;
	else if (keycode == KEY_A)
		mlx->angle += 0.1;
	else if (keycode == KEY_D)
		mlx->angle -= 0.1;
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

int	handle_key(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	control_key(keycode, mlx);
	projection_key(keycode, mlx);
	draw(mlx);
	return (0);
}