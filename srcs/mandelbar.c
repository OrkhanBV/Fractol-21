/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 23:52:49 by jremarqu          #+#    #+#             */
/*   Updated: 2020/04/27 03:30:43 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	mandelbar_iter(t_fractal *fr)
{
	while (fr->z_real * fr->z_real + fr->z_im * fr->z_im < 4 &&
			fr->iter < fr->limit)
	{
		fr->tmp = fr->z_real;
		fr->z_real = fr->z_real * fr->z_real - fr->z_im * fr->z_im + fr->c_r;
		fr->z_im = -2 * fr->z_im * fr->tmp + fr->c_im;
		fr->iter++;
	}
}

void	ft_mandelbar(t_fractal *fr)
{
	while (fr->y < fr->height)
	{
		while (fr->x < fr->width)
		{
			fr->c_r = fr->x / fr->zoom + fr->x_shift;
			fr->c_im = fr->y / fr->zoom + fr->y_shift;
			fr->z_real = 0;
			fr->z_im = 0;
			mandelbar_iter(fr);
			color_of_pix(fr);
			fr->iter = 0;
			fr->x++;
		}
		fr->y++;
		fr->x = 0;
	}
	fr->x = 0;
	fr->y = 0;
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img_ptr, 0, 0);
}
