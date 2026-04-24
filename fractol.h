#ifndef FRACTOL_H
# define FRACTOL_H

// INCLUDES

# include <mlx.h>
# include <X11/X.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <math.h>

// MACROS

//window-size
# define HEIGHT 800
#define WIDTH 800

//key-press
# define ESC 65307
# define ARROW_RIGHT 65363
# define ARROW_LEFT 65361
# define ARROW_UP 65362
# define ARROW_DOWN 65364

//mouse-wheel
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef unsigned int	t_color;

typedef struct s_mlx
{
	void			*mlx;
	void 			*img;
	void			*win;
	t_color			*addr;
} t_mlx;

typedef struct s_view
{
	double  offset_x;
	double  offset_y;
	double  zoom;

} t_view;
typedef struct s_fractol
{
	char  	*name;
	double  julia_cx;
	double  julia_cy;
	int		iteration;
} t_fractol;

#endif
