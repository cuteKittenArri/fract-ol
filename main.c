#include "fractol.h"

static void	invalid_arg_print(void)
{
	ft_putstr_fd("option 1: \n./fractol mandelbrot\n", 1);
	ft_putstr_fd("option 2: \n./fractol julia <real> <imaginaty>\n", 1);
	ft_putstr_fd("example: \n./fractol julia -0.4 0.6\n", 1);
	exit(1);
}

int	main(int argc, char **argv)
{
	
}
