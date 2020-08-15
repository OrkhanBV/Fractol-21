/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorising.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 22:24:46 by jremarqu          #+#    #+#             */
/*   Updated: 2020/05/01 16:16:56 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	pix_to_img(t_fractal *fr, int color)
{
	fr->color = mlx_get_color_value(fr->mlx, color);
	ft_memmove((fr->img_data + (4 * (fr->width * fr->y))
		+ (4 * (fr->x))), &fr->color, sizeof(int));
}

void	color_of_pix(t_fractal *fr)
{
	if (fr->iter == fr->limit)
		pix_to_img(fr, 0);
	else
		pix_to_img(fr, (fr->iter * 8000000));
}

/*
**по сути mlx_get_color_value позволяет
**нам присвоить интовому числу соответствующий цвет
**если занырнуть в функцию будет видно как это происходит, при
**желании можно написать что-то своё
**
**Ссылка на статью как сделать преход цветов более плавными
**http://www.iquilezles.org/www/articles/mset_smooth/mset_smooth.htm
*/
