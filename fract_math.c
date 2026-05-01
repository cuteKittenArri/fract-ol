/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meth.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmuller <stmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 23:15:17 by stmuller          #+#    #+#             */
/*   Updated: 2026/04/30 05:05:31 by stmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_color	coloring(int iterations)
{
	return (iterations * PURPLE);
}

static void	math_init(double x, double y, t_fractol *fractol,
		t_math *math_obj)
{
	if (fractol->name)
	{
		math_obj->z_real = 0.0;
		math_obj->z_imag = 0.0;
		math_obj->c_real = x + fractol->offset_x;
		math_obj->c_imag = y + fractol->offset_y;
	}
	else
	{
		math_obj->z_real = x + fractol->offset_x;
		math_obj->z_imag = y + fractol->offset_y;
		math_obj->c_real = fractol->julia_cx;
		math_obj->c_imag = fractol->julia_cy;
	}
}

t_color	fract_math(double x, double y, t_fractol *fractol)
{
	int			i;
	double		tmp;
	t_math	math_obj;

	i = 0;
	math_init(x * fractol->zoom, y * fractol->zoom, fractol, &math_obj);
	while (i < fractol->iteration)
	{
		if ((math_obj.z_real * math_obj.z_real)
			+ (math_obj.z_imag * math_obj.z_imag) > 4)
			return (coloring(i));
		tmp = (math_obj.z_real * math_obj.z_real)
			- (math_obj.z_imag * math_obj.z_imag) + math_obj.c_real;
		math_obj.z_imag = 2 * math_obj.z_real * math_obj.z_imag
			+ math_obj.c_imag;
		math_obj.z_real = tmp;
		i++;
	}
	return (BLACK);
}
