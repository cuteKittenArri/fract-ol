/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmuller <stmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 23:19:28 by stmuller          #+#    #+#             */
/*   Updated: 2026/04/30 05:06:19 by stmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define WIDTH 420

//key-press
# define ESC 65307

//mouse-wheel
# define SCROLL_UP 4
# define SCROLL_DOWN 5

//colors
# define PURPLE 0x6a329f
# define BLACK 0x000000

typedef unsigned int	t_color;

typedef struct s_data
{
	int	px_bits;
	int	line_lengh;
	int	endian;
}	t_data;

typedef struct s_fractol
{
	int		name;
	double	julia_cx;
	double	julia_cy;
	int		iteration;
	double	zoom;
}	t_fractol;

typedef struct s_mlx
{
	void		*mlx;
	void		*img;
	void		*win;
	char		*addr;
	t_data		*data;
	t_fractol	*fractol;
}	t_mlx;

typedef struct s_math
{
	double	z_real;
	double	z_imag;
	double	c_real;
	double	c_imag;	
}	t_math;

//  LIB-UTILS
void	ft_putstr_fd(char *str, int fd);
int		ft_strncmp(char *s1, char *s2, int n);
double	atod(char *str);

//  FRACTOL-UTILS

t_color	fract_math(double x, double y, t_fractol *fractol);
int		render_main(t_mlx *mlx);
int		closer(t_mlx *mlx);
int		key_handler(int key, t_mlx *mlx);
int		mouse_handler(int button, int x, int y, t_mlx *mlx);

#endif
