#include "fdf.h"

t_map *init_map(void)
{
	t_map *map;
	map = malloc(sizeof(t_map));
	if (!map)
		exit_str(ALLOC_ERR);
	map->lines_capacity = 16;
	map->lines = malloc(sizeof(int *) * map->lines_capacity);
	if(!map->lines)
		exit_str(ALLOC_ERR);
	map->width = 0;
	map->height = 0;
	map->zoom = 0;
	return(map);
}

t_mlx	*init_mlx(t_map *map)
{
	t_mlx *mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	if(!mlx)
		exit_str(MLX_ERR);
	mlx->window = mlx_new_window(mlx-mlx, WIN_WIDTH, WIN_HEIGHT, "Fdf");
	if (!mlx->window)
		exit_str(MLX_ERR);
	mlx->mouse = malloc(sizeof(t_mouse));
	if(!mlx->mouse)
		exit_str(ALLOC_ERR);
	mlx->img = NULL;
	mlx->addr = NULL;
	mlx->offset_x = WIN_WIDTH / 2;
	mlx->offset_y = WIN_HEIGHT / 2;
	mlx->raise_z = 1;
	mlx->angle = M_PI * 30.0 / 180.0;
	mlx->projection = 1;
	mlx->onclick = 0;
	mlx->map = map;
	mlx->map->zoom = WIN_HEIGHT / (mlx->map->width + mlx->map->height);
	return(mlx);
}
