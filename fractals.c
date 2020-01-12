/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:40:27 by ngontjar          #+#    #+#             */
/*   Updated: 2020/01/13 00:42:43 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			julia(int x, int y, t_program *prog)
{
	t_complex	c;
	t_complex	z;
	int			iterator;
	double		rr;
	double		ii;

	c.r = (CMIN / prog->fractal.zoom) +
		(x * prog->fractal.delta.x) + prog->fractal.position.x;
	c.i = (CMAX / prog->fractal.zoom) -
		(y * prog->fractal.delta.y) + prog->fractal.position.y;
	z.r = c.r;
	z.i = c.i;
	iterator = -1;
	while (++iterator < prog->fractal.resolution)
	{
		rr = z.r * z.r;
		ii = z.i * z.i;
		if (rr + ii > 4)
			break ;
		z.i = (2 * z.r * z.i) + (prog->fractal.position.y - prog->mouse.y);
		z.r = (rr - ii) + (prog->fractal.position.x + prog->mouse.x);
	}
	return (iterator);
}

int			mandelbrot(int x, int y, t_program *prog)
{
	t_complex	c;
	t_complex	z;
	int			iterator;
	double		rr;
	double		ii;

	c.r = (CMIN / prog->fractal.zoom) +
		(x * prog->fractal.delta.x) + prog->fractal.position.x;
	c.i = (CMAX / prog->fractal.zoom) -
		(y * prog->fractal.delta.y) + prog->fractal.position.y;
	z.r = c.r;
	z.i = c.i;
	iterator = -1;
	while (++iterator < prog->fractal.resolution)
	{
		rr = z.r * z.r;
		ii = z.i * z.i;
		if (rr + ii > 4)
			break ;
		z.i = (2 * z.r * z.i) + c.i;
		z.r = (rr - ii) + c.r;
	}
	return (iterator);
}

int			burning_ship(int x, int y, t_program *prog)
{
	t_complex	c;
	t_complex	z;
	double		rr;
	double		ii;
	int			iterator;

	c.r = (CMIN / prog->fractal.zoom) +
		(x * prog->fractal.delta.x) + prog->fractal.position.x;
	c.i = (CMAX / prog->fractal.zoom) -
		(y * prog->fractal.delta.y) + prog->fractal.position.y;
	z.r = c.r;
	z.i = c.i;
	iterator = -1;
	while (++iterator < prog->fractal.resolution)
	{
		z.r = fabs(z.r);
		z.i = fabs(z.i);
		rr = z.r * z.r;
		ii = z.i * z.i;
		if (rr + ii > 4)
			break ;
		z.i = (2 * z.r * z.i) + c.i;
		z.r = (rr - ii) + c.r;
	}
	return (iterator);
}

int			burning_julia(int x, int y, t_program *prog)
{
	t_complex	c;
	t_complex	z;
	double		rr;
	double		ii;
	int			iterator;

	c.r = (CMIN / prog->fractal.zoom) +
		(x * prog->fractal.delta.x) + prog->fractal.position.x;
	c.i = (CMAX / prog->fractal.zoom) -
		(y * prog->fractal.delta.y) + prog->fractal.position.y;
	z.r = c.r;
	z.i = c.i;
	iterator = -1;
	while (++iterator < prog->fractal.resolution)
	{
		z.r = fabs(z.r);
		z.i = fabs(z.i);
		rr = z.r * z.r;
		ii = z.i * z.i;
		if (rr + ii > 4)
			break ;
		z.i = (2 * z.r * z.i) + (prog->fractal.position.y - prog->mouse.y);
		z.r = (rr - ii) + (prog->fractal.position.x + prog->mouse.x);
	}
	return (iterator);
}
