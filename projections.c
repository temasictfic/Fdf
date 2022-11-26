#include "fdf.h"

void conic(t_p *p, int z, double lambda, t_mlx *mlx)
{
	p.x = cos(M_PI * 15 / 180) * sin(lambda / sqrt(pow(z, 2) -1) / sin(1 / acos(z + (M_PI * 15 / 180));
	p.y = cos(M_PI * 15 / 180) * cos(lambda / sqrt(pow(z, 2) -1) / sin(1 / acos(z + (M_PI * 15 / 180));
}

void apply_conic(t_p *p1, t_p *p2, t_z *z, t_mlx *mlx)
{
	double lambda = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	conic(p1, z->z1, mlx);
	conic(p2, z->z2, mlx);
}

void iso(t_p *p, int z, t_mlx *mlx)
{
	p->x = (p->x - p->y) * cos(mlx->angle);
	p->y = (-z * mlx->raise_z) + (p->x + p->y) * sin(mlx->angle);

}

void apply_iso(t_p *p1, t_p *p2, t_z *z, t_mlx *mlx)
{
        iso(p1, z->z1, mlx);
        iso(p2, z->z2, mlx);
}

