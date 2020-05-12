/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chameleon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 21:44:30 by jremarqu          #+#    #+#             */
/*   Updated: 2020/04/27 03:32:52 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/*
** данный фрактал разновидность Джулии
*/

void	chameleon_iter(t_fractal *fr)
{
	while (fr->z_real * fr->z_real + fr->z_im *
		fr->z_im < 4 && fr->iter < fr->limit)
	{
		fr->tmp = fr->z_real;
		fr->z_real = fr->z_real * fr->z_real - fr->z_im * fr->z_im + fr->c_r;
		fr->z_im = -2 * fr->z_im * fr->tmp + fr->c_im;
		fr->iter++;
	}
}

void	ft_chameleon(t_fractal *fr)
{
	while (fr->y < fr->height)
	{
		while (fr->x < fr->width)
		{
			fr->c_r = fr->c_r;
			fr->c_im = fr->c_im;
			fr->z_real = fr->x / fr->zoom + fr->x_shift;
			fr->z_im = fr->y / fr->zoom + fr->y_shift;
			chameleon_iter(fr);
			color_of_pix(fr);
			fr->iter = 50;
			fr->x++;
		}
		fr->y++;
		fr->x = 0;
	}
	fr->x = 0;
	fr->y = 0;
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img_ptr, 0, 0);
}
