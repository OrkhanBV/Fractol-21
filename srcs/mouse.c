/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 00:12:00 by jremarqu          #+#    #+#             */
/*   Updated: 2020/04/27 03:31:49 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/*
** mouse key codes
** nbr 4 it is roller and mean run to forward
** nbr 5 it is roller and mean run to back
** nbr 1 it is left button of mouse
** nbr 2 it is midl button of mouse ander roller
** nbr 3 it is right button of mouse
** в зависимости отоперационной системы кодировка меняется
** printf("mouse key_kode = %d\n", m_key);
** поэтому если необходимо проверить на другой операционке
** то принтф нам в помощь
*/

int		ft_mouse_manage(int m_key, int x, int y, t_fractal *fr)
{
	if (m_key == 4 || m_key == 1)
	{
		ft_zoomin(x, y, fr);
		ft_fractal_driwing(fr);
	}
	if (m_key == 5 || m_key == 3)
	{
		ft_zoomout(x, y, fr);
		ft_fractal_driwing(fr);
	}
	return (0);
}

void	mouse_role_manage(int m_key, int x, int y, t_fractal *fr)
{
	if (m_key == 4 || m_key == 1)
	{
		ft_zoomin(x, y, fr);
		ft_fractal_driwing(fr);
	}
	if (m_key == 5 || m_key == 2)
	{
		ft_zoomout(x, y, fr);
		ft_fractal_driwing(fr);
	}
}

int		mouse_julia(int x, int y, t_fractal *fr)
{
	if (fr->switch_mouse_j == 1)
	{
		if (x < fr->width && y < fr->height)
		{
			fr->c_r = 4 * ((double)x / (fr->width) - 0.5);
			fr->c_im = 4 * ((double)(fr->height - y) / fr->height - 0.5);
		}
		ft_julia(fr);
	}
	return (0);
}
