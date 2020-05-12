/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 22:50:34 by jremarqu          #+#    #+#             */
/*   Updated: 2020/04/28 00:00:37 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_choose_fractal(t_fractal *fr, char *argv)
{
	if (ft_strcmp("mandelbrot", argv) == 0)
		fr->type_fractal = 1;
	else if (ft_strcmp("julia", argv) == 0)
		fr->type_fractal = 2;
	else if (ft_strcmp("chameleon", argv) == 0)
		fr->type_fractal = 3;
	else if (ft_strcmp("mandelbar", argv) == 0)
		fr->type_fractal = 4;
	else
	{
		ft_usage(0);
		exit(0);
	}
}

int		exit_program(void *param)
{
	(void)param;
	return (0);
}

void	ft_usage(void *param)
{
	(void)param;
	ft_putendl("dear user, you need write next");
	ft_putendl("mandelbrot or ->>");
	ft_putendl("julia or ->>");
	ft_putendl("mandelbar or->>");
	ft_putendl("chameleon");
}
