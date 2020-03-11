/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:59:48 by lseema            #+#    #+#             */
/*   Updated: 2020/02/23 20:27:56 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# define W	800
# define H	600

typedef	struct			s_complex
{
	long double			min_in;
	long double			max_in;
	long double			min_out;
	long double			max_out;

}						t_complex;

typedef struct			s_main
{
	int					(*f)(struct s_main *e, int x, int y);
	void				*mlx_ptr;
	void				*win_ptr;
	void				*image_ptr;
	char				*image;
	int					bpp;
	int					en;
	int					ln;
	int					red;
	int					green;
	int					blue;
	int					choose_color;
	int					fractal;
	int					is_julia_motion;
	int					iteration;
	float				max_iteration;
	long double			c_re;
	long double			c_im;
	long double			min_x;
	long double			max_x;
	long double			min_y;
	long double			max_y;
	long double			zoom;
}						t_main;

void					start_initialize(t_main *e);
long double				ft_complex(long double x, t_complex p);
int						mandelbrot(t_main *e, int x, int y);
int						julia(t_main *e, int x, int y);
int						burning_ship(t_main *e, int x, int y);
int						key_draw(int keycode, t_main *e);
void					foreach_pixel(t_main *e);
void					put_pixel_to_img(t_main *e, int x, int y);
int						init_mlx(t_main *e);
void					draw(t_main *e);
void					choose_color(t_main *e, int color);
int						mouse_zoom(int keycode, int x, int y, t_main *e);
int						julia_change_complex(int x, int y, t_main *e);
t_complex				new_complex(long double a, long double b, long double c,
	long double d);
void					print_console(t_main *e);
int						case_fractal(char *str);
int						escape(void);

#endif
