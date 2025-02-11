/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:21:27 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/11 13:52:20 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

// DO NOW NOW: Check subject and do 
// DO NOW: Fractal (Mandelbrot part) video by Oceano

// BUGS: 
// BUG: changing color brightness over any keys moving -> check after mlx_hook

// Mandelbrot & Julia (different Julias with diff input values)
// Window management must be smooth, resizing etc.
// Check all fts and correct them in *.h.
// Check for fractol vs fractal and make it right!!
// How to deal with wrong inputs for Julia? Do I want to deal with it? Yes I do. Do I though?
// Color mgmt, do % and add color depending on which # it ends?

// BONUS:
// More parameters from command line if needed.
// Extra fractal (third)
// Zoom follows the cursor (hook to center on cursor's position?)
// Make the color range shift (ask Zuzi).
// Change number of iterations with a + -. Due it via hooks in fract


// Here I will initialize all hooks
void	init_hooks_and_events(t_fractal *fract)
{
	mlx_key_hook(fract->mlx_cnct, &keys_mgmt, fract);
	mlx_close_hook(fract->mlx_cnct, &close_mgmt, fract->mlx_cnct);
	mlx_scroll_hook(fract->mlx_cnct, &scroll_mgmt, fract);
//	mlx_cursor_hook(fract->mlx_cnct, &cursor_mgmt, fract->mlx_cnct); // for bonus zooming
//	mlx_mouse_hook() // Or maybe this one for the zooming bonus?
// 	hook for pressing/clicking to change between different color schemes.
}

// Here I set values to all important stuff. Set up sub-functions.
void	data_init(t_fractal *fract, char *argv)
{
	// set random stuff
	fract->max_iter = 30; // 30
	fract->name = argv;
	// set map_x/y
	// old
	fract->map_x.old.min = 0;		// 0
	fract->map_x.old.max = WIDTH;	// WIDTH
	fract->map_y.old.min = 0;		// 0
	fract->map_y.old.max = HEIGHT;	// HEIGHT
	// new base
	fract->map_x.new.min = -2.5;  	// -2.5
	fract->map_x.new.max = 1.1;		// 1.1
	fract->map_y.new.min = 1.8;		// 1.8
	fract->map_y.new.max = -1.8;	// -1.8
	// zoom
	fract->zoom_x.center = 0;
	fract->zoom_x.old = fract->map_x.new.max - fract->map_x.new.min;
	fract->zoom_x.new = 0;
	fract->zoom_y.center = 0;
	fract->zoom_y.old = fract->map_y.new.max - fract->map_y.new.min;
	fract->zoom_y.new = 0;
	// set shift.x/y
	fract->shift.x = 0.0;
	fract->shift.y = 0.0;
	// color set 1
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

	// checks for correct arguments
	if (!((argc == 2 && ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
			|| (argc == 4 && ft_strncmp(argv[1], "Julia", 6) == 0)))
	{
		ft_printf("incorrect argument(s)\n\ttype \"Mandelbrot\""
			"\n     or\ttype \"Julia\", value 1 and value 2\n");
		return (EXIT_FAILURE);
	}
	// initialize all the fract struct's data
	data_init(&fract, argv[1]);
	// initialization	 of the MLX and the image stuff
	init_fract(&fract);
	// Rendering of the image, adding pixels.
	rndr_fract(&fract);

//	mlx_loop_hook(fract.mlx_cnct, ft_move, &fract); freeze
	mlx_loop(fract.mlx_cnct);
	mlx_terminate(fract.mlx_cnct);
	return (EXIT_SUCCESS);
}

// FUNCTIONs
// mlx_init() - initializes the connection to MLX.
// mlx_new_image() - creates a new blank image. // buffer probably
// mlx_image_to_window() - It will put buffered image to a window.
// mlx_loop_hook() - It will keep "open" function in an infinite loop.
// mlx_is_key_down() - Do something if specific keyboard is pressed.
// mlx_close_window() - It tells mlx to close the open window.
// mlx_terminate() - Terminates MLX and cleans up any left used resourcel.
// mlx_loop() - It will keep the window open, infinite loop.
// mlx_terminate() - It will terminate the mlx connection

// -----------------------------------------------------------------------

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

// BUGS FIXED

// BUG: last x pixel is being rendered on the first position.
// FIXED with changed pre/post incrementation. 