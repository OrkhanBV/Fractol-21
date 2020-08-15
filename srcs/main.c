/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 23:39:28 by jremarqu          #+#    #+#             */
/*   Updated: 2020/05/01 16:15:51 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_fractal_driwing(t_fractal *fr)
{
	if (fr->type_fractal == 1)
		ft_mandelbrot(fr);
	else if (fr->type_fractal == 2)
		ft_julia(fr);
	else if (fr->type_fractal == 3)
		ft_chameleon(fr);
	else if (fr->type_fractal == 4)
		ft_mandelbar(fr);
	else
		exit(0);
}

void	ft_initialization_mlx(t_fractal *fr)
{
	fr->mlx = mlx_init();
	fr->win = mlx_new_window(fr->mlx, fr->width,
							fr->height, "JREMARQU_FRACTAL");
	fr->img_ptr = mlx_new_image(fr->mlx, fr->width, fr->height);
	fr->img_data = mlx_get_data_addr(fr->img_ptr, &(fr->bitspp),
									&(fr->size_line), &(fr->endian));
}

void	ft_event_manager(t_fractal *fr)
{
	mlx_hook(fr->win, 6, 1L << 6, mouse_julia, fr);
	mlx_key_hook(fr->win, ft_key_manager, fr);
	mlx_mouse_hook(fr->win, ft_mouse_manage, fr);
	mlx_hook(fr->win, 17, 0L, exit_program, fr);
	mlx_loop(fr->mlx);
}

void	ft_main_program(t_fractal *fr)
{
	ft_initialization_fractals(fr);
	ft_initialization_mlx(fr);
	ft_fractal_driwing(fr);
	ft_event_manager(fr);
}

int		main(int argc, char **argv)
{
	t_fractal	fr;
	void		*param;

	param = 0;
	if (argc != 2)
	{
		ft_usage(param);
		return (0);
	}
	ft_choose_fractal(&fr, argv[1]);
	ft_main_program(&fr);
	return (0);
}

/*
** Множеством Фату полинома f(z) = z2 + c называется такое
** подмножество множества комплексных чисел,
** для каждой точки которого, поведение функции под действием
** итераций является нормальным, т.е. траектория точек генерируемая
** итерациями, не сильно изменяется при изменении начальных условий в
** некоторой небольшой окрестности начальной точки. Обозначается F(f).
** Множеством Жюлиа полинома f(z) = z2 + c соответственно называется
** такое подмножество множества комплексных чисел, для каждой точки
** которого, поведение функции под действием итераций является
** хаотичным, т.е. небольшие изменения в начальных условиях в некоторой
** небольшой окрестности начальной точки, значительно влияют на траекторию.
** Обозначается J(f)
** Множество Мандельброта — это такое множество параметров c полинома
** f(z) = z2 + c, для которого множества Жюлиа связно (связанное пространство—
** непустое топологическое пространство, которое невозможно разбить на два
** непустых непересекающихся открытых подмножества.).
** Полином - это многочлены от одной переменной - функции типа
** F(X) = Co + C1X + ... + CnX^n
** https://habr.com/ru/post/206516/
*/

/*
**О типах фрактала
**http://rusproject.narod.ru/article/fractals.htm
*/
