/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:47:32 by ngontjar          #+#    #+#             */
/*   Updated: 2020/01/13 00:46:18 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		keyboard(int key, void *param)
{
	t_program	*prog;
	double		resolution;

	prog = (t_program *)param;
	resolution = prog->fractal.resolution;
	if ((key == numPlus) && (resolution + 4 <= 170))
	{
		prog->fractal.resolution += 4;
	}
	else if ((key == numMin) && (resolution - 4 >= 1))
	{
		prog->fractal.resolution -= 4;
	}
	else if (key == ESC)
	{
		exit(0);
	}
	draw(prog);
	return (TRUE);
}

int		mouse(int key, int x, int y, void *param)
{
	t_program	*prog;
	t_range		zoomed;

	prog = (t_program *)param;
	if (key == WhUp)
	{
		prog->fractal.zoom *= 1.5;
	}
	else if ((key == WhDn) && (prog->fractal.zoom * 0.75 > 0.5))
	{
		prog->fractal.zoom *= 0.75;
	}
	zoomed.min = CMIN / prog->fractal.zoom;
	zoomed.max = CMAX / prog->fractal.zoom;
	prog->fractal.delta.x = (zoomed.max - zoomed.min) / (WIDTH - 1);
	prog->fractal.delta.y = (zoomed.max - zoomed.min) / (HEIGHT - 1);
	prog->fractal.position.x += prog->fractal.delta.x * (x - WIDTH * 0.5);
	prog->fractal.position.y -= prog->fractal.delta.y * (y - HEIGHT * 0.5);
	draw(prog);
	return (TRUE);
}

int		mouse_move(int x, int y, void *param)
{
	t_program	*prog;

	prog = (t_program *)param;
	prog->mouse.x = prog->fractal.delta.x * (x - WIDTH * 0.5);
	prog->mouse.y = prog->fractal.delta.y * (y - HEIGHT * 0.5);
	if (prog->fractal.func == &julia || prog->fractal.func == &burning_julia)
		draw(prog);
	return (TRUE);
}
