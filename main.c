/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 04:45:24 by sciftci           #+#    #+#             */
/*   Updated: 2022/12/29 20:37:55 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_program(char *str)
{
	perror(str);
	exit(1);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	t_mlx	*mlx;
	t_mouse	*mouse;

	mouse = NULL;
	if (argc != 2)
		exit_program(USAGE_ERROR);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_program(OPEN_MAP_ERROR);
	map = init_map();
	if (!map)
		exit_program(INIT_MAP_ERROR);
	read_map(fd, map);
	mlx = init_mlx(map);
	draw(mlx);
	setup_controls(mlx);
	mlx_loop(mlx->mlx);
	close(fd);
}
