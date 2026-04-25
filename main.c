#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>

static void	invalid_arg_print(void)
{
	ft_putstr_fd("option 1: \n./fractol mandelbrot\n", 1);
	ft_putstr_fd("option 2: \n./fractol julia <real> <imaginaty>\n", 1);
	ft_putstr_fd("example: \n./fractol julia -0.4 0.6\n", 1);
	exit(1);
}

static void	valid(int argc, char **argv, t_fractol *fractol)
{
	if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		fractol->name = 0;
		fractol->julia_cx = atod(argv[2]);
		fractol->julia_cy = atod(argv[3]);
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		fractol->name = 1;
	else
		invalid_arg_print();	
}

static void	init_mlx(t_mlx *mlx, t_fractol *fractol)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		exit(1);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "fractol");
	if (!mlx->win)
	{
	 free(mlx->mlx);
	 exit(1);
	}
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!mlx->img)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		free(mlx->mlx);
		exit(1);		
	}
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->data->px_bits, &mlx->data->line_lengh, &mlx->data->endian);
}

int	main(int argc, char **argv)
{
	t_mlx		*mlx;
	t_fractol	*fractol;

	fractol->zoom = 1.0;
	fractol->iteration = 69;
	init_mlx(mlx, fractol);
	render_main(mlx, fractol);
	
}
