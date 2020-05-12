/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 23:02:27 by jremarqu          #+#    #+#             */
/*   Updated: 2020/04/27 03:47:14 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/*
** Удивительно, но множества Жулиа образуются по той же самой формуле, что и
** множество Мандельброта. Множество Жулиа было изобретено французским
** математиком Гастоном Жулиа, по имени которого и было названо множество.
** Первый вопрос, возникающий после визуального знакомства с множествами
** Мандельброта и Жулиа это "если оба фрактала сгенерированы по одной формуле,
** почему они такие разные?" Сначала посмотрите на картинки множества Жулиа.
** Достаточно странно, но существуют разные типы множеств Жулиа. При рисовании
** фрактала с использованием различных начальных точек (чтобы начать процесс
** итераций), генерируются различные изображения. Это применимо только
** ко множеству Жулиа.
** Хотя это нельзя увидеть на картинке, фрактал Мандельброта - это, на самом
** деле, множество фракталов Жулиа, соединенных вместе. Каждая точка
** (или координата) множества Мандельброта соответствует фракталу Жулиа.
** http://grafika.me/node/31
*/

void	julia_iter(t_fractal *fr)
{
	while (fr->z_real * fr->z_real + fr->z_im *
			fr->z_im < 4 && fr->iter < fr->limit)
	{
		fr->tmp = fr->z_real;
		fr->z_real = fr->z_real * fr->z_real - fr->z_im * fr->z_im + fr->c_r;
		fr->z_im = 2 * fr->z_im * fr->tmp + fr->c_im;
		fr->iter++;
	}
}

void	ft_julia(t_fractal *fr)
{
	while (fr->y < fr->height)
	{
		while (fr->x < fr->width)
		{
			fr->c_r = fr->c_r;
			fr->c_im = fr->c_im;
			fr->z_real = fr->x / fr->zoom + fr->x_shift;
			fr->z_im = fr->y / fr->zoom + fr->y_shift;
			julia_iter(fr);
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
