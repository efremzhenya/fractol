/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:49:06 by lseema            #+#    #+#             */
/*   Updated: 2020/02/23 20:58:04 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

static void		guess_color(int key, t_main *e)
{
	if (key >= 18 && key <= 21)
	{
		if (key == 18)
			e->choose_color = 0;
		else if (key == 19)
			e->choose_color = 1;
		else if (key == 20)
			e->choose_color = 2;
		else
			e->choose_color = 3;
		draw(e);
	}
}

static int		move(int keycode, t_main *e)
{
	if (keycode == 125)
	{
		e->min_y += 0.1 * e->zoom;
		e->max_y += 0.1 * e->zoom;
		draw(e);
	}
	if (keycode == 126)
	{
		e->min_y -= 0.1 * e->zoom;
		e->max_y -= 0.1 * e->zoom;
		draw(e);
	}
	if (keycode == 124)
	{
		e->min_x += 0.1 * e->zoom;
		e->max_x += 0.1 * e->zoom;
		draw(e);
	}
	if (keycode == 123)
	{
		e->min_x -= 0.1 * e->zoom;
		e->max_x -= 0.1 * e->zoom;
		draw(e);
	}
	return (-1);
}

int				key_draw(int keycode, t_main *e)
{
	if (keycode == 53)
		exit(1);
	move(keycode, e);
	if (keycode == 256)
		e->is_julia_motion = e->is_julia_motion ? 0 : 1;
	if (keycode == 13)
	{
		e->max_iteration += 10;
		draw(e);
	}
	if (keycode == 14)
	{
		e->max_iteration -= 10;
		draw(e);
	}
	if (keycode == 49)
	{
		start_initialize(e);
		draw(e);
	}
	guess_color(keycode, e);
	return (-1);
}
