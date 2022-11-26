#include "fdf.h"

void exit_str(char *str)
{
	perror(str);
	exit(1);
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
	draw(mlx);
	control(mlx);
	mlx_loop(mlx->mlx);
}
