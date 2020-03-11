/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:08:44 by lseema            #+#    #+#             */
/*   Updated: 2020/02/23 20:12:59 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

static void		more_colors(t_main *e, int depth)
{
	if (e->choose_color == 2)
	{
		e->red = (depth * depth * 20) % 255;
		e->blue = (depth * depth * 70) % 255;
		e->green = (depth * 40) % 255;
	}
	else if (e->choose_color == 3)
	{
		e->red = (depth * 5) % 255;
		e->blue = (depth * 5) % 255;
		e->green = (depth * 5) % 255;
	}
}

void			choose_color(t_main *e, int depth)
{
	if (e->choose_color == 0)
	{
		if (e->max_iteration == depth)
		{
			e->red = 0;
			e->blue = 0;
			e->green = 0;
		}
		else
		{
			e->red = (depth * 3) % 255;
			e->blue = (depth * 7) % 255;
			e->green = (depth * 4) % 255;
		}
	}
	else if (e->choose_color == 1)
	{
		e->red = (depth * 7) % 255;
		e->blue = (depth * 4) % 70;
		e->green = (depth * 2) % 4;
	}
	else
		more_colors(e, depth);
}
