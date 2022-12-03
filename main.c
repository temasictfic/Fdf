#include "fdf.h"

void exit_str(char *str)
{
	perror(str);
	exit(1);
}

void	controls(t_mlx *mlx)
{
	mlx_hook(mlx->window, EVENT_ON_KEYDOWN, NO_MASK, handle_key, mlx);
	mlx_hook(mlx->window, EVENT_ON_DESTROY, NO_MASK, escape, mlx);
	mlx_hook(mlx->window, EVENT_ON_MOUSEDOWN, NO_MASK, mouse, mlx);
	mlx_hook(mlx->window, EVENT_ON_MOUSEMOVE, NO_MASK, mouse_move, mlx);
	mlx_hook(mlx->window, EVENT_ON_MOUSEUP, NO_MASK, mouse_release, mlx);
	//init_img(mlx); ?? drawın içinde var
	draw(mlx);
}

int main(int argc, char **argv)
{
	int fd;

	t_map	*map;
	t_mlx	*mlx;
	t_mouse	*mouse;

	mouse = NULL;
	if (argc != 2)
		exit_str(USG_ERR);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_str(OPEN_MAP_ERR);
	map = init_map();
	read_map(fd, map);
	close(fd);
	mlx = init_mlx(map);
	//draw(mlx); ?? controls içinde var
	controls(mlx);
	mlx_loop(mlx->mlx);
}
