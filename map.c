#include "fdf.h"

void read_map(int fd, t_map *map)
{
	
	char	*line;
	char	**lines;
	int	width;

	width = 0;
	line = get_next_line(fd);
	while(*line != '\0')
	{
		lines = ft_split(line, ' ');
		if (!lines)
			exit_str(READ_MAP_ERR);
		while(lines[width] != NULL)
			width++;
		fill_lines(lines, width, map);
		line = get_next_line(fd);
	}
}

void incr_capacity(t_map *map)
{
	int **new_lines;

	map->lines_capacity <<= 1;
	new_lines = malloc(sizeof(inr *) * map->lines_capacity);
	if(!new_lines)
		exit_str(ALLOC_ERR);
	ft_memcpy(new_lines, map->lines, map->height * sizeof(int *));
	free(map->lines);
	map->lines = new_lines;
}

void fill_lines(char **lines, int width, t_map *map)
{
	int *pixels;
	int i;

	i = -1;
	if(!map->width)
		map->width = width;
	else if (width != map->width)
		exit_str(READ_MAP_ERR);
	pixels = malloc(sizeof(int) * width);
	if (!pixels)
		exit_str(ALLOC_ERR);
	while(++i < width)
		pixels[i] = ft_atoi(lines[i]);
	if (map->height == map->lines_capacity)
		incr_capacity(map);
	map->lines[map->height++] = pixels;
}
