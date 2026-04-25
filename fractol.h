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
# define HEIGHT 420
#define WIDTH 420

//key-press
# define ESC 65307

//mouse-wheel
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef unsigned int	t_color;

typedef struct s_data
{
	int	px_bits;
	int	line_lengh;
	int	endian;
} t_data;

typedef struct s_mlx
{
	void	*mlx;
	void 	*img;
	void	*win;
	char	*addr;
	t_data	*data;
} t_mlx;

typedef struct s_fractol
{
	int  	name;
	double  julia_cx;
	double  julia_cy;
	int		iteration;
	double  zoom;
} t_fractol;

//  LIB-UTILS
void	ft_putstr_fd(char *str, int fd);
int	ft_strncmp(char *s1, char *s2, int n);
double	atod(char *str);


#endif
