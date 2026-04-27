#include "fractol.h"

static t_color	coloring(int iterations)
{
	return (iterations * PURPLE);
}

static void	meth_init(double x, double y, t_fractol *fractol, t_lameth *math_obj)
{
	if (fractol->name)
	{
		math_obj->z_real = 0.0;
		math_obj->z_imag = 0.0;
		math_obj->c_real = x;
		math_obj->c_imag = y;
	}
	else
	{
		math_obj->z_real = x;
		math_obj->z_imag = y;
		math_obj->c_real = fractol->julia_cx;
		math_obj->c_imag = fractol->julia_cy;
	}
}

t_color	meth(double x, double y, t_fractol *fractol)
{
	int			i;
	double		tmp;
	t_lameth	math_obj;

	i = 0;
	meth_init(x, y, fractol, &math_obj);
	while (i < fractol->iteration)
	{
		if ((math_obj.z_real * math_obj.z_real) + (math_obj.z_imag * math_obj.z_imag) > 4)
			return coloring(i);
		tmp = (math_obj.z_real * math_obj.z_real) - (math_obj.z_imag * math_obj.z_imag) + math_obj.c_real;
		math_obj.z_imag = 2 * math_obj.z_real * math_obj.z_imag + math_obj.c_imag;
		math_obj.z_real = tmp;
		i++;
	}
	return (BLACK);
}
