/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:48:55 by ngontjar          #+#    #+#             */
/*   Updated: 2020/01/12 23:53:17 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	clamp(double in, double min, double max)
{
	if (in < min)
		return (min);
	else if (in > max)
		return (max);
	else
		return (in);
}

int		rgb2int(double r, double g, double b)
{
	int color;

	color = 0;
	r = clamp(r, 0, 1);
	g = clamp(g, 0, 1);
	b = clamp(b, 0, 1);
	color |= (int)(r * 255) << 16;
	color |= (int)(g * 255) << 8;
	color |= (int)(b * 255);
	return (color);
}

/*
**double map(double in, double in_min, double in_max,
**			double to_min, double to_max)
**{
**	return (to_min + (to_max - to_min) / (in_max - in_min) * (in - in_min));
**}
**
**static int gradient(int percent, int start, int end)
**{
**	int red;
**	int green;
**	int blue;
**
**	red = start & 0xFF;
**	green = (start >> 8) & 0xFF;
**	blue = (start >> 16) & 0xFF;
**}
**
**t_rgb		hsv2rgb(t_hsv color)
**{
**	double	i;
**	double	f;
**	double	p;
**	double	q;
**	double	t;
**	int		mod;
**
**	i = floor(color.h * 6);
**	f = color.h * 6 - i;
**	p = color.v * (1 - color.s);
**	q = color.v * (1 - f * color.s);
**	t = color.v * (1 - (1 - f) * color.s);
**	if ((mod = (int)i % 6) == 0)
**		return ((t_rgb){color.v * 255, t * 255, p * 255});
**	else if (mod == 1)
**		return ((t_rgb){q * 255, color.v * 255, p * 255});
**	else if (mod == 2)
**		return ((t_rgb){p * 255, color.v * 255, t * 255});
**	else if (mod == 3)
**		return ((t_rgb){p * 255, q * 255, color.v * 255});
**	else if (mod == 4)
**		return ((t_rgb){t * 255, p * 255, color.v * 255});
**	else
**		return ((t_rgb){color.v * 255, p * 255, q * 255});
**}
*/
