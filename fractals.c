/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:56:42 by lseema            #+#    #+#             */
/*   Updated: 2020/02/23 20:21:25 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int		mandelbrot(t_main *e, int x, int y)
{
	long double mx;
	long double my;
	long double x_temp;
	long double c_im;
	long double c_re;

	e->iteration = 0;
	mx = 0.0;
	my = 0.0;
	c_re = ft_complex(x, new_complex(0, W, e->min_x, e->max_x));
	c_im = ft_complex(y, new_complex(0, H, e->min_y, e->max_y));
	while (e->max_iteration > e->iteration)
	{
		x_temp = (mx * mx - my * my) + c_re;
		my = 2.0f * mx * my + c_im;
		mx = x_temp;
		if ((mx * mx + my * my) > 4.0f)
			break ;
		e->iteration++;
	}
	return (e->iteration);
}

int		julia(t_main *e, int x, int y)
{
	long double mx;
	long double my;
	long double x_temp;

	e->iteration = 0;
	mx = ft_complex(x, new_complex(0, W, e->min_x, e->max_x));
	my = ft_complex(y, new_complex(0, H, e->min_y, e->max_y));
	while (e->max_iteration > e->iteration)
	{
		x_temp = (mx * mx - my * my) + e->c_re;
		my = 2.0f * mx * my + e->c_im;
		mx = x_temp;
		if ((mx * mx + my * my) > 4.0f)
			break ;
		e->iteration++;
	}
	return (e->iteration);
}

int		burning_ship(t_main *e, int x, int y)
{
	long double mx;
	long double my;
	long double c_im;
	long double c_re;
	long double x_temp;

	e->iteration = 0;
	mx = 0.0;
	my = 0.0;
	c_re = ft_complex(x, new_complex(0, W, e->min_x, e->max_x));
	c_im = ft_complex(y, new_complex(0, H, e->min_y, e->max_y));
	while (e->max_iteration > e->iteration)
	{
		x_temp = (mx * mx - my * my) + c_re;
		my = fabsl(2.0 * mx * my + c_im);
		mx = fabsl(x_temp);
		if ((mx * mx + my * my) > 4.0f)
			break ;
		e->iteration++;
	}
	return (e->iteration);
}
