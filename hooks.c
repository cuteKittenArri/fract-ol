/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmuller <stmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 23:17:15 by stmuller          #+#    #+#             */
/*   Updated: 2026/04/27 23:19:10 by stmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>

int	closer(t_mlx *mlx);

int	key_handler(int key, t_mlx *mlx)
{
	if (key == ESC)
		closer(mlx);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (button == SCROLL_UP)
		mlx->fractol->zoom *= 0.95;
	else if (button == SCROLL_DOWN)
		mlx->fractol->zoom *= 1.05;
	else
		return (0);
	return (0);
}

int	closer(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(0);
}
