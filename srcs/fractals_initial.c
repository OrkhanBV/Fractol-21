/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_initial.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 22:37:31 by jremarqu          #+#    #+#             */
/*   Updated: 2020/04/28 00:29:18 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init_chameleon(t_fractal *fr)
{
	fr->width = 1000;
	fr->height = 1000;
	fr->x = 0;
	fr->y = 0;
	fr->iter = 0;
	fr->x_shift = -2.4;
	fr->y_shift = -1.7;
	fr->c_r = 0.29;
	fr->c_im = 0.02;
	fr->limit = 100;
	fr->zoom = 200;
	fr->switch_mouse_j = 0;
}

void	init_mandelbar(t_fractal *fr)
{
	fr->width = 1000;
	fr->height = 1000;
	fr->x = 0;
	fr->y = 0;
	fr->iter = 0;
	fr->x_shift = -2.5;
	fr->y_shift = -2.1;
	fr->limit = 100;
	fr->zoom = 150;
	fr->switch_mouse_j = 0;
}

void	init_mandelbrot(t_fractal *fr)
{
	fr->width = 1000;
	fr->height = 1000;
	fr->x = 0;
	fr->y = 0;
	fr->iter = 0;
	fr->x_shift = -2.5;
	fr->y_shift = -2.1;
	fr->limit = 100;
	fr->zoom = 150;
	fr->switch_mouse_j = 0;
}

void	init_julia(t_fractal *fr)
{
	fr->width = 1000;
	fr->height = 1000;
	fr->x_prev = 0;
	fr->y_prev = 0;
	fr->x = 0;
	fr->y = 0;
	fr->iter = 0;
	fr->x_shift = -2.5;
	fr->y_shift = -2.0;
	fr->c_r = -0.63;
	fr->c_im = -0.54;
	fr->limit = 100;
	fr->zoom = 200;
	fr->switch_mouse_j = 1;
}

void	ft_initialization_fractals(t_fractal *fr)
{
	if (fr->type_fractal == 1)
		init_mandelbrot(fr);
	else if (fr->type_fractal == 2)
		init_julia(fr);
	else if (fr->type_fractal == 3)
		init_chameleon(fr);
	else if (fr->type_fractal == 4)
		init_mandelbar(fr);
	else
	{
		exit(0);
	}
}
