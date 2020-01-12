/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 09:22:20 by ngontjar          #+#    #+#             */
/*   Updated: 2020/01/13 00:44:34 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "stdio.h"
# include "libft/libft.h"
# include "mlx.h"
# include <math.h>

# define WIDTH 500
# define HEIGHT 500
# define CMIN -2.0
# define CMAX 2.0

/*
** # define MAP(in, inMIN, inMAX, toMIN, toMAX) \
** (toMIN + (1.0 * (toMAX - toMIN) / (inMAX - inMIN)) * (in - inMIN))
*/

typedef struct	s_xy
{
	double x;
	double y;
}				t_xy;

typedef struct	s_range
{
	double min;
	double max;
}				t_range;

typedef struct	s_complex
{
	double r;
	double i;
}				t_complex;

typedef struct	s_program t_program;

typedef struct	s_fract
{
	int		(*func)(int, int, struct s_program*);
	t_xy	position;
	t_xy	delta;
	double	resolution;
	double	zoom;
}				t_fract;

typedef struct	s_image
{
	void	*ptr;
	int		*data;
	int		bpp;
	int		line;
	int		endian;
}				t_image;

typedef struct	s_program
{
	void	*mlx;
	void	*win;
	t_image	buffer;
	t_xy	mouse;
	t_fract	fractal;
}				t_program;

typedef struct	s_rgb
{
	double r;
	double g;
	double b;
}				t_rgb;

typedef struct	s_hsv
{
	double h;
	double s;
	double v;
}				t_hsv;

enum			e_mouse
{
	LMB = 1,
	RMB = 2,
	MMB = 3,
	WhDn = 4,
	WhUp = 5
};

enum			e_key
{
	ESC = 53,
	numPlus = 69,
	numMin = 78
};

int		keyboard(int key, void *param);
int		mouse(int key, int x, int y, void *param);
int		mouse_move(int x, int y, void *param);

int		julia(int x, int y, t_program *prog);
int		mandelbrot(int x, int y, t_program *prog);
int		burning_ship(int x, int y, t_program *prog);
int		burning_julia(int x, int y, t_program *prog);

double	clamp(double in, double min, double max);
int		rgb2int(double r, double g, double b);

void	draw(t_program *prog);

#endif
