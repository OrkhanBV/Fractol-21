/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 23:36:31 by jremarqu          #+#    #+#             */
/*   Updated: 2020/04/27 03:47:50 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/*
** 65361 стрелка влево <-
** 65363 стрелка вправо ->
** 65362 стрелка вверх
** 65364 стрелка вниз
** 65307 esc
*/

void	ft_x_diriction(int key, t_fractal *fr)
{
	if (key == 65361)
	{
		fr->x_shift = fr->x_shift + 0.01;
		ft_fractal_driwing(fr);
	}
	if (key == 65363)
	{
		fr->x_shift = fr->x_shift - 0.01;
		ft_fractal_driwing(fr);
	}
}

void	ft_y_diriction(int key, t_fractal *fr)
{
	if (key == 65362)
	{
		fr->y_shift = fr->y_shift + 0.01;
		ft_fractal_driwing(fr);
	}
	if (key == 65364)
	{
		fr->y_shift = fr->y_shift - 0.01;
		ft_fractal_driwing(fr);
	}
}

void	ft_esc_exit_key(int key)
{
	if (key == 65307)
		exit(1);
}

int		ft_key_manager(int key, t_fractal *fr)
{
	ft_esc_exit_key(key);
	ft_x_diriction(key, fr);
	ft_y_diriction(key, fr);
	return (0);
}
