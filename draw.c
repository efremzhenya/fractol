/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:08:55 by lseema            #+#    #+#             */
/*   Updated: 2020/02/23 20:53:09 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

t_complex	new_complex(long double a, long double b, long double c,
	long double d)
{
	return ((t_complex){.min_in = a, .max_in = b, .min_out = c, .max_out = d});
}

long double	ft_complex(long double x, t_complex p)
{
	return (p.min_out + (p.max_out - p.min_out)
		* ((x - p.min_in) / (p.max_in - p.min_in)));
}

void		foreach_pixel(t_main *e)
{
	int x;
	int y;
	int color;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			color = e->f(e, x, y);
			choose_color(e, color);
			put_pixel_to_img(e, x, y);
			x++;
		}
		y++;
	}
}

void		draw(t_main *e)
{
	mlx_clear_window(e->mlx_ptr, e->win_ptr);
	foreach_pixel(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->image_ptr, 0, 0);
}

void		put_pixel_to_img(t_main *e, int x, int y)
{
	if ((x >= 0 || x <= W) && (y >= 0 || y <= H))
	{
		e->image[(x * 4) + (y * W * 4) + 2] = e->red;
		e->image[(x * 4) + (y * W * 4) + 1] = e->green;
		e->image[(x * 4) + (y * W * 4)] = e->blue;
	}
}
