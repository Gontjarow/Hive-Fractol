/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 10:25:02 by ngontjar          #+#    #+#             */
/*   Updated: 2020/01/13 01:02:55 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw(t_program *prog)
{
	int		x;
	int		y;
	int		iterations;
	double	ratio;
	int		color;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			iterations = prog->fractal.func(x, y, prog);
			ratio = iterations / prog->fractal.resolution;
			color = rgb2int(ratio * ratio, ratio, ratio);
			prog->buffer.data[(y * WIDTH) + x] = color;
		}
	}
	mlx_put_image_to_window(prog->mlx, prog->win, prog->buffer.ptr, 0, 0);
}

static void	die(const char *message)
{
	ft_putendl(ft_strjoin("Error: ", message));
	exit(0);
}

static void	setup(t_program *prog, char *title,
	int (*fractal_function)(int, int, t_program*))
{
	prog->mlx = mlx_init();
	if (prog->mlx == NULL)
		die("Failed to initialize MLX.");
	prog->win = mlx_new_window(prog->mlx, WIDTH, HEIGHT, title);
	if (prog->win == NULL)
		die("Failed to create a window.");
	prog->buffer.ptr = mlx_new_image(prog->mlx, WIDTH, HEIGHT);
	if (prog->buffer.ptr == NULL)
		die("Failed to allocate frame buffer.");
	prog->buffer.data = (int *)mlx_get_data_addr(prog->buffer.ptr,
		&prog->buffer.bpp, &prog->buffer.line, &prog->buffer.endian);
	;
	prog->mouse.x = WIDTH / 2;
	prog->mouse.y = HEIGHT / 2;
	prog->fractal.position.x = 0;
	prog->fractal.position.y = 0;
	prog->fractal.delta.x = (CMAX - CMIN) / WIDTH;
	prog->fractal.delta.y = (CMAX - CMIN) / HEIGHT;
	prog->fractal.resolution = 2;
	prog->fractal.zoom = 0.5;
	prog->fractal.func = fractal_function;
	mlx_mouse_hook(prog->win, &mouse, prog);
	mlx_key_hook(prog->win, &keyboard, prog);
	mlx_hook(prog->win, 6, (1L << 6), mouse_move, prog);
}

int			main(int argc, char **argv)
{
	t_program prog;

	if (argc == 2)
	{
		prog.mlx = NULL;
		if (ft_strequ(argv[1], "mandelbrot"))
			setup(&prog, "Mandelbrot", &mandelbrot);
		else if (ft_strequ(argv[1], "julia"))
			setup(&prog, "Julia", &julia);
		else if (ft_strequ(argv[1], "burningship"))
			setup(&prog, "Burning Ship", &burning_ship);
		else if (ft_strequ(argv[1], "burningjulia"))
			setup(&prog, "Burning Ship - Julia", &burning_julia);
		if (prog.mlx)
			mlx_loop(prog.mlx);
	}
	ft_putstr("Available patterns: ");
	ft_putendl("mandelbrot, julia, burningship, burningjulia");
	return (0);
}
