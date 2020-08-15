/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 00:25:30 by jremarqu          #+#    #+#             */
/*   Updated: 2020/04/27 04:01:44 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_zoomin(int x, int y, t_fractal *fr)
{
	double		new_x;
	double		new_y;

	if (y > 0 && x > 0)
	{
		new_x = (x / fr->zoom) + fr->x_shift;
		new_y = (y / fr->zoom) + fr->y_shift;
		fr->zoom = fr->zoom * 1.22;
		fr->x_shift = new_x - (x / fr->zoom);
		fr->y_shift = new_y - (y / fr->zoom);
		ft_fractal_driwing(fr);
	}
}

void	ft_zoomout(int x, int y, t_fractal *fr)
{
	double		new_x;
	double		new_y;

	if (y > 0 && x > 0)
	{
		new_x = (x / fr->zoom) + fr->x_shift;
		new_y = (y / fr->zoom) + fr->y_shift;
		fr->zoom = fr->zoom / 1.22;
		fr->x_shift = new_x - (x / fr->zoom);
		fr->y_shift = new_y - (y / fr->zoom);
		ft_fractal_driwing(fr);
	}
}
