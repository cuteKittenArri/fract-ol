#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>

static void	put_px(int x, int y, t_color color, t_mlx *mlx)
{
	int	offset;

	offset = (y * mlx->data->line_lengh) + (x * (mlx->data->px_bits / 8));
	*(t_color *)(mlx->addr + offset) = color;
}

double	to_math(double start, double min, double max, double end)
{
	return ((max - min) * (start / end) + start);	
}

static void	render_pxl(double x, double y, t_fractol *fractol, t_mlx *mlx)
{
	double	math_x;
	double	math_y;
	t_color	color;

	math_x = ((4 * (x / WIDTH) + x) * fractol->zoom);
	math_y = ((4 * (y / HEIGHT) + y) * fractol->zoom);
	if (fractol->name)
		color = mandel_math(math_x, math_y, fractol);
	else
		color = julia_math(math_x, math_y, fractol);
	put_px((int)x, (int)y, color, mlx);
}

void	render_main(t_mlx *mlx, t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			render_pxl(x, y, fractol, mlx);
	}
	mlx_put_image_to_window(mlx, mlx->win, mlx->img, 0, 0);
}
