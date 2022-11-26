#include "fdf.h"

t_p point(int x, int y)
{
	t_p p;

	p.x = x;
	p.y = y;
	return (p);
}

void init_img(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, 1920, 1080);
	if (!mlx->img)
		exit_str(IMG_ERR);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
	if (!mlx->addr)
		exit_str(IMG_ERR);
}

void	destroy_img(t_mlx	*mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->addr = NULL;
	mlx->img = NULL;

}

void	draw(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	init_img(mlx);
	while(y < mlx->map->height)
	{
		x = 0;
		while (x < mlx->map->width)
		{
			if (x != mlx->map->width-1)
				bresenham(point(x,y), point(x + 1, y), mlx);
			if (y != mlx->map->height -1)
				bresenham(point(x, y), point(x, y+1), mlx);
			x++;
		
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0); // 0 lar ney?
	destroy_img(mlx);
}
