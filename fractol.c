/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:21:27 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/12 23:58:46 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

// Here I will initialize all hooks
void	init_hooks_and_events(t_fractal *fract)
{
	mlx_key_hook(fract->mlx_cnct, &keys_mgmt, fract);
	mlx_close_hook(fract->mlx_cnct, &close_mgmt, fract);
	mlx_scroll_hook(fract->mlx_cnct, &scroll_mgmt, fract);
	mlx_resize_hook(fract->mlx_cnct, &resize_mgmt, fract);
}

// Setting up special data for particular sets
void	set_sets(t_fractal *fract, char **argv)
{
	if (ft_strncmp(fract->name, "Mandelbrot", 11) == 0)
	{
		fract->map_x.new.min = -2.5;
		fract->map_x.new.max = 1.1;
		fract->map_y.new.min = 1.8;
		fract->map_y.new.max = -1.8;
		fract->max_iter = 25;
	}
	else if (ft_strncmp(fract->name, "Julia", 6) == 0)
	{
		fract->julia = ft_atoi(argv[2]);
		fract->map_x.new.min = -1.6;
		fract->map_x.new.max = 1.6;
		fract->map_y.new.min = 1.6;
		fract->map_y.new.max = -1.6;
		fract->max_iter = 50;
		set_julias(fract);
	}
}

// Here I set values to all important stuff. Set up sub-functions.
void	data_init(t_fractal *fract, char **argv)
{
	fract->name = argv[1];
	set_sets(fract, argv);
	fract->side_x = 800;
	fract->side_y = 800;
	fract->map_x.old.min = 0;
	fract->map_x.old.max = fract->side_x;
	fract->map_y.old.min = 0;
	fract->map_y.old.max = fract->side_y;
	fract->zoom_x.center = -0.7;
	fract->zoom_x.old = fract->map_x.new.max - fract->map_x.new.min;
	fract->zoom_x.new = 0;
	fract->zoom_y.center = 0;
	fract->zoom_y.old = fract->map_y.new.max - fract->map_y.new.min;
	fract->zoom_y.new = 0;
	fract->shift.x = 0.0;
	fract->shift.y = 0.0;
	fract->mouse.x = 0;
	fract->mouse.y = 0;
	fract->color.old.min = 0;
	fract->color.old.max = fract->max_iter;
	fract->color.new.min = BLACK;
	fract->color.new.max = WHITE;
}

// init function for MLX, image, hooks.
void	init_fract(t_fractal *fract)
{
	fract->mlx_cnct = mlx_init(WIDTH, HEIGHT, fract->name, true);
	if (fract->mlx_cnct == NULL)
		error_msg_malloc();
	fract->img = mlx_new_image(fract->mlx_cnct, WIDTH, HEIGHT);
	if (fract->img == NULL)
		error_msg_malloc();
	init_hooks_and_events(fract);
}

// Check for correct arguments, fork to init, rndr and loop + clean at the end.
int	main(int argc, char **argv)
{
	t_fractal	fract;

	if (!((argc == 2 && ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
			|| (argc == 3 && ft_strncmp(argv[1], "Julia", 6) == 0)))
	{
		ft_printf("incorrect argument(s)\n\ttype \"Mandelbrot\""
			"\n     or\ttype \"Julia\" and a nbr (1-5)\n");
		return (EXIT_FAILURE);
	}
	data_init(&fract, argv);
	init_fract(&fract);
	rndr_fract(&fract);
	mlx_loop(fract.mlx_cnct);
	mlx_terminate(fract.mlx_cnct);
	return (EXIT_SUCCESS);
}
