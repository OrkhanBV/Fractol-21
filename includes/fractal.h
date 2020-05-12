/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 00:44:23 by jremarqu          #+#    #+#             */
/*   Updated: 2020/04/30 19:08:02 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include "libft/libft.h"

typedef struct	s_fractal
{
	int			type_fractal;
	void		*mlx;
	void		*win;
	void		*img_ptr;
	char		*img_data;
	int			endian;
	int			width;
	int			height;
	int			bitspp;
	int			size_line;
	int			signal;
	int			color;
	int			limit;
	double		zoom;
	int			iter;
	int			x_prev;
	int			x;
	int			y_prev;
	int			y;
	double		x_shift;
	double		y_shift;
	double		c_r;
	double		c_im;
	double		tmp;
	double		z_real;
	double		z_im;
	int			switch_mouse_j;
}				t_fractal;

void			ft_choose_fractal(t_fractal *fr, char *argv);
void			pix_to_img(t_fractal *fr, int color);
void			color_of_pix(t_fractal *fr);
int				mouse_julia(int x, int y, t_fractal *fr);
void			ft_julia(t_fractal *fr);
void			ft_initialization_fractals(t_fractal *fr);
void			ft_initialization_mlx(t_fractal *fr);
void			ft_chameleon(t_fractal *fr);
void			ft_mandelbar(t_fractal *fr);
void			ft_mandelbrot(t_fractal *fr);
void			ft_julia(t_fractal *fr);
void			color_of_pix(t_fractal *fr);
int				exit_program(void *param);
void			ft_usage(void *param);
void			ft_fractal_driwing(t_fractal *fr);
void			ft_zoomin(int x, int y, t_fractal *fr);
void			ft_zoomout(int x, int y, t_fractal *fr);
int				ft_mouse_manage(int m_key, int x, int y, t_fractal *fr);
int				mouse_julia(int x, int y, t_fractal *fr);
int				ft_key_manager(int key, t_fractal *fr);

#endif
