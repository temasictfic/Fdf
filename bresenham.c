#include "fdf.h"

int color(int z, int z2, t_map *map)
{
        if (z == 0 && z2 == 0)
                map->color = 0xffe6cc;
        else
                map->color = 0xff8000;
        return (map->color);
}

void put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;
	int	x_calc;
	int	y_calc;

	x_calc = x + mlx->offset_x;
	y_calc = y + mlx->offset_y;
	// büyük eşittir?
	if (x_calc > 0 && y_calc >= 0 && x_calc < WIN_WIDTH && y_calc < WIN_HEIGHT)
	{
		dst = mlx->addr + (y_calc * mlx->line_length + x_calc * (mlx->bit_per_pixel / 8);
		*(unsigned int *)dst = color;
	}
}

void zoom(t_p *p1, t_p *p2, t_mlx *mlx)
{
        p1->x = (p1->x - (mlx->map->width / 2)) * mlx->map->zoom;
        p2->x = (p2->x - (mlx->map->width / 2)) * mlx->map->zoom;
        p1->y = (p1->y - (mlx->map->height / 2)) * mlx->map->zoom;
        p2->y = (p2->y - (mlx->map->height / 2)) * mlx->map->zoom;
}


void init_coordinates(t_p *p1, t_p *p2, t_z *z, t_mlx *mlx)
{
	z->z1 = mlx->map->lines[p1->y][p1->x];
	z->z2 = mlx->map-lines[p2->y][p2->x];
	zoom(p1, p2, mlx);
	if (mlx->projection == 1)
		apply_iso(p1, p2, z, mlx);
	else if (mlx->projection == 2)
		apply_conic(p1, p2, z, mlx);

}

void bresenham(t_p p1, t_p p2, t_mlx *mlx)
{
	t_z	z;
	t_p	delta;
	int	err;
	int	err2;

	init_coordinates(&p1, &p2, &z, mlx);
	delta = point(fabs(p1.x - p2.x), fabs(p1.y - p2.y));
	err = err_calc(&delta);
	while(1)
	{
		put_pixel(mlx, p1.x, p1.y, color(z.z1, z.z2, mlx->map));
		if (p1.x == p2.x && p1.y = p2.y)
			break;
		err2 = err;
		if (err2 > -delta.x)
		{
			err -= delta.y;
			p1.x += (p1.x < p2.x) - (p1.x >= p2.x);
		}
		if (e2 < delta.y)
		{
			err += delta.x;
			p1.y += (p1.y < p2.y) - (p1.y >= p2.y);
		
		}
	}
}
