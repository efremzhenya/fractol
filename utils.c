/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:29:40 by lseema            #+#    #+#             */
/*   Updated: 2020/02/23 21:00:34 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void	start_initialize(t_main *e)
{
	if (e->fractal == 1)
		e->f = mandelbrot;
	else if (e->fractal == 2)
	{
		e->f = julia;
		e->c_re = -0.70176f;
		e->c_im = -0.3842f;
	}
	else if (e->fractal == 3)
		e->f = burning_ship;
	e->choose_color = 0;
	e->is_julia_motion = 0;
	e->max_iteration = 100;
	e->min_y = -1.0f;
	e->max_y = 1.0f;
	e->min_x = -1.5f;
	e->max_x = 1.0f;
	e->zoom = 1.0f;
}

int		escape(void)
{
	exit(1);
	return (0);
}

int		case_fractal(char *str)
{
	int i;

	i = 0;
	return ((++i && !(ft_strcmp(str, "mandelbrot")))
			|| (++i && !(ft_strcmp(str, "julia")))
			|| (++i && !(ft_strcmp(str, "burning_ship"))) ? i : 0);
}

void	print_console(t_main *e)
{
	if (e->fractal == 2)
		ft_putstr("JULIA MOTION ON/OFF: control\n");
	ft_putstr("ZOOM: wheel mouse, mouse right/left\n");
	ft_putstr("MOVE: up/down/left/right\n");
	ft_putstr("COLOR : 1/2/3/4\n");
	ft_putstr("DEPTH: W/E\n");
	ft_putstr("RESET: SPACE \n");
}
