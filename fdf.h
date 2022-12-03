#ifndef FDF_H
# define FDF_H

#include "mlx/mlx.h"
#include "gnl/get_next_line.h"
#include <math.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef WIN_WIDTH
 #define WIN_WIDTH 1280
#endif

#ifndef WIN_HEIGHT
 #define WIN_HEIGHT 720
#endif
// Bisque
#ifndef COLOR_LOW
 #define COLOR_LOW 0xffe6cc
#endif
// Orange
#ifndef COLOR_HIGH
 #define COLOR_HIGH 0xff8000
#endif

#define MLX_ERR "Mlx Error!"
#define IMG_ERR "Image Initialization Error!"
#define USG_ERR "Usage: ./fdf <.fdf map file>"
#define OPEN_MAP_ERR "Failed to open map!"
#define INIT_MAP_ERR "Failed to initialize map!"
#define READ_MAP_ERR "Failed to read map!"
#define ALLOC_ERR "Failed to allocate memory!"

#define EVENT_ON_KEYDOWN 2
#define EVENT_ON_KEYUP   3
#define EVENT_ON_MOUSEDOWN 4
#define EVENT_ON_MOUSEUP 5
#define EVENT_ON_MOUSEMOVE 6
#define EVENT_ON_DESTROY 17
#define NO_MASK 0

#define MOUSE_LEFT 1
#define MOUSE_RIGHT 2
#define MOUSE_MIDDLE 3
#define MOUSE_SCROLLUP 4
#define MOUSE_SCROLLDOWN 5

#define KEY_ESC 53
// Offset X +-
#define KEY_ARROWLEFT 123
#define KEY_ARROWRIGHT 124
// Offset Y +-
#define KEY_ARROWUP 126
#define KEY_ARROWDOWN 125
// Zoom +-
#define KEY_I 34
#define KEY_O 31
// Raise Z, Lower Z
#define KEY_W 13
#define KEY_S 1
// Angle +-
#define KEY_A 0
#define KEY_D 2
// Projections paralel, iso, conic
#define KEY_ONE 18
#define KEY_TWO 19
#define KEY_THREE 20

typedef struct s_p
{
    int x;
    int y;
}   t_p;

typedef struct s_z
{
    int    z1;
    int    z2;
}       t_z;

typedef struct s_map
{
    int     width;
    int     height;
    int     **lines;
    int     lines_capacity;
    int     zoom;
    int     color;
}       t_map;

typedef struct s_mouse
{
	int		x;
	int		y;
}				t_mouse;

typedef struct s_mlx
{
    void    *mlx;
    void    *window;
    void    *img;
    void    *addr;
    t_map   *map;
    t_mouse *mouse;
    int bits_per_pixel;
    int line_length;
    int endian;
    int offset_x;
    int offset_y;
    int raise_z;
    int projection;
    int onclick;
    float   angle;
}       t_mlx;

// Initialization
t_map	*init_map(void);
t_mlx	*init_mlx(t_map *map);
// Read map & Fill lines;
void read_map(int fd, t_map *map);
void fill_lines(char **lines, int width, t_map *map);
// Projections
void apply_conic(t_p *p1, t_p *p2, t_z *z, t_mlx *mlx);
void apply_iso(t_p *p1, t_p *p2, t_z *z, t_mlx *mlx);
// Draw
t_p p(int x, int y);
void bresenham(t_p p1, t_p p2, t_mlx *mlx);
void	draw(t_mlx *mlx);
// Utils
int err_calc(t_p *delta);
long int	ft_atoi(const char *str);
char	**ft_split(char const *str, char c);
// Events
int	handle_key(int keycode, void *param);
int	escape(void *param);
int	mouse(int keycode, int x, int y, void *param);
int	mouse_move(int x, int y, void *param);
int	mouse_release(int keycode, int x, int y, void *param);

#endif