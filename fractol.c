/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:21:27 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/12 22:18:11 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

// Check all fts and correct them in *.h.
// Check for fractol vs fractal and make it right!!
// How to deal with wrong inputs for Julia?

// BONUS:
// Play with different color sets. Leave it for now.
// Extra fractal (third)

// Here I will initialize all hooks
void	init_hooks_and_events(t_fractal *fract)
{
	mlx_key_hook(fract->mlx_cnct, &keys_mgmt, fract);
	mlx_close_hook(fract->mlx_cnct, &close_mgmt, fract->mlx_cnct);
	mlx_scroll_hook(fract->mlx_cnct, &scroll_mgmt, fract);
//	mlx_resize_hook(fract->mlx_cnct, &resize_mgmt, fract);
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
	fract->map_x.old.min = 0;
	fract->map_x.old.max = WIDTH;
	fract->map_y.old.min = 0;
	fract->map_y.old.max = HEIGHT;
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
	fract->mlx_cnct = mlx_init(WIDTH, HEIGHT, fract->name, false);
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

// -----------------------------------------------------------------------

// Change number of iterations with a + -. Due it via hooks in fract // DONE
// Zoom follows the cursor (hook to center on cursor's position?) // DONE
// Make the color range shift (ask Zuzi). // DONE
// 3 different color sets. // DONE
// Mouse wheel zooms in & out almost infinitively. // DONE
// Use diff colours for diff iterations of fractals. // DONE
// ESC and "X" must exit smoothly. // DONE
// Data init function: max_iter, old/new min/max, fract name.. // DONE
// Update "rescaling" and rm fifth argument. // DONE
// Add hooks for arrow moving. // DONE
// WORKING PROTOTYPE of Mandelbrot!!! // DONE
// DO NOW: add checks for init part for failing. // DONE
// math_utils.c -> addition, squaring, escape value 4(Pythagoras) // DONE
// fractol struct and keep adding more if needed. // DONE
// Calculate the math yourself -> z^2 + c -> almost // DONE
// typedef struct for s_complex -> real and imaginary with doubles // DONE
// Start up checks. // DONE
// Put image onto window // DONE
// key hook to print pressed key // DONE
// test case for MLX42, not working...
// setup MLX42 correctly, MLX42.h and make and make clean // DONE
// Have window on screen // DONE
