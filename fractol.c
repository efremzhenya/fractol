/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:12:59 by lseema            #+#    #+#             */
/*   Updated: 2020/02/23 20:57:44 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int			init_mlx(t_main *e)
{
	if (!(e->mlx_ptr = mlx_init()) ||
		!(e->win_ptr = mlx_new_window(e->mlx_ptr, W, H, "Fract'ol")) ||
		!(e->image_ptr = mlx_new_image(e->mlx_ptr, W, H)) ||
		!(e->image = mlx_get_data_addr(e->image_ptr, &e->bpp, &e->ln, &e->en)))
		return (0);
	e->bpp /= 8;
	return (1);
}

int			main(int argc, char *argv[])
{
	t_main	*e;
	int		fractal;

	if (argc == 2 && (fractal = case_fractal(argv[1])))
	{
		if (!(e = malloc(sizeof(t_main))) || !(init_mlx(e)))
			return (0);
		e->fractal = fractal;
		print_console(e);
		start_initialize(e);
		foreach_pixel(e);
		draw(e);
		mlx_hook(e->win_ptr, 2, 5, key_draw, e);
		mlx_hook(e->win_ptr, 17, 1L << 17, escape, NULL);
		mlx_mouse_hook(e->win_ptr, mouse_zoom, e);
		mlx_hook(e->win_ptr, 6, 1L << 6, julia_change_complex, e);
		mlx_loop(e->mlx_ptr);
	}
	else
		ft_putstr("Available params:\n mandelbrot\n julia\n burning_ship\n");
	return (0);
}
