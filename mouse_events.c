/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:56:49 by lseema            #+#    #+#             */
/*   Updated: 2020/02/23 21:00:56 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

static int	zoom_in(int x, int y, t_main *e)
{
	long double	zoom_step;
	long double	move_x;
	long double	move_y;

	move_x = (long double)x * (long double)((e->max_x - e->min_x)
		/ (long double)W) + (long double)e->min_x;
	move_y = (long double)y * (long double)((e->max_y - e->min_y)
		/ (long double)H) + (long double)e->min_y;
	zoom_step = 0.9f;
	e->zoom *= zoom_step;
	e->max_x = (e->max_x * zoom_step) + move_x * (1 - zoom_step);
	e->min_x = (e->min_x * zoom_step) + move_x * (1 - zoom_step);
	e->max_y = (e->max_y * zoom_step) + move_y * (1 - zoom_step);
	e->min_y = (e->min_y * zoom_step) + move_y * (1 - zoom_step);
	draw(e);
	return (0);
}

static int	zoom_out(int x, int y, t_main *e)
{
	long double	zoom_step;
	long double	move_x;
	long double	move_y;

	if (e->zoom <= 2)
	{
		move_x = (long double)x * (long double)((e->max_x - e->min_x)
			/ (long double)W) + e->min_x;
		move_y = (long double)y * ((long double)(e->max_y - e->min_y)
			/ (long double)H) + e->min_y;
		zoom_step = 1.1f;
		e->zoom *= zoom_step;
		e->max_x = e->max_x * zoom_step + move_x * (1 - zoom_step);
		e->min_x = e->min_x * zoom_step + move_x * (1 - zoom_step);
		e->max_y = e->max_y * zoom_step + move_y * (1 - zoom_step);
		e->min_y = e->min_y * zoom_step + move_y * (1 - zoom_step);
		draw(e);
	}
	return (0);
}

int			mouse_zoom(int key, int x, int y, t_main *e)
{
	if (key == 5 || key == 1)
		zoom_in(x, y, e);
	else if (key == 4 || key == 2)
		zoom_out(x, y, e);
	return (0);
}

int			julia_change_complex(int x, int y, t_main *e)
{
	if (e->is_julia_motion)
	{
		e->c_re = ft_complex(x, new_complex(0, W, -1, 1));
		e->c_im = ft_complex(y, new_complex(0, H, -1, 1));
		draw(e);
	}
	return (0);
}
