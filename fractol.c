/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:21:27 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/08 22:25:57 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// DO NOW NOW: Add hooks for arrow moving.
// DO NOW: Fractal (Mandelbrot part) video by Oceano

// BUGS: 
// BUG: changing color brightness over arrow keys moving -> check after mlx_hook

// Data init function: max_iter, old/new min/max, fract name, 
// Update "rescaling" and rm fifth argument.
// Mandelbrot & Julia (different Julias with diff input values)
// Mouse wheel zooms in & out almost infinitively.
// Maybe put secon img in the color of the outside iter if less/more than x iter.
// Use diff colours for diff iterations of fractals.
// Window management must be smooth, resizing etc.
// ESC and "X" must exit smoothly.
// Check all fts and correct them in *.h.
// MiniLibX(MLX42) use of images is necessary. -> What does this mean??
// Check for fractol vs fractal and make it right!!
// How to deal with wrong inputs for Julia? Do I want to deal with it? Yes aI do.
// Color mgmt, do % and add color depending on which # it ends?

// BONUS:
// More parameters from command line if needed.
// Extra fractal (third)
// Zoom follows the cursor (hook to center on cursor's position?)
// Moving the view by pressing arrow keys. (similar to test "test")
// Make the color range shift (ask Zuzi).
// Change number of iterations with a + -. Due it via hooks in fract

// All key hooks, including hook to close after pressing ESC.
void	keys_mgmt(mlx_key_data_t keydata, void *param)
{
	t_fractal *fract = param;
	
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		fract->shift.y -= 0.35;
		rndr_fract(fract);
	}
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		fract->shift.y += 0.35;
		rndr_fract(fract);
	}
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		fract->shift.x += 0.35;
		rndr_fract(fract);
	}
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		fract->shift.x -= 0.35;
		rndr_fract(fract);
	}
//	rndr_fract(fract);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		// Check which leaks are OK and which not with someone.
		write(1, "ESCAPED\n", 8);
		mlx_close_window(fract->mlx_cnct);
		mlx_terminate(fract->mlx_cnct);
		exit(EXIT_SUCCESS);
	}
	// if (mlx_is_key_down(fract->mlx_cnct, MLX_KEY_UP))
	// {
	// 	fract->shift.y -= 0.2;
	// 	rndr_fract(fract);
	// }	
	// if (mlx_is_key_down(fract->mlx_cnct, MLX_KEY_DOWN))
	// {
	// 	fract->shift.y += 0.2;
	// 	rndr_fract(fract);
	// }			
	// if (mlx_is_key_down(fract->mlx_cnct, MLX_KEY_LEFT))
	// {
	// 	fract->shift.x += 0.2;
	// 	rndr_fract(fract);
	// }	
	// if (mlx_is_key_down(fract->mlx_cnct, MLX_KEY_RIGHT))
	// {
	// 	fract->shift.x -= 0.2;
	// 	rndr_fract(fract);
	// }	
	// moving via shift UP. DOWN. LEFT. RIGHT   TODO

	// increase and decrease iterations with '+' '-' TODO
}

// typedef void (*mlx_scrollfunc)(double xdelta, double ydelta, void* param);
void	scroll_mgmt(double xdelta, double ydelta, void *param)
{
	t_fractal	*fract;
	
	(void)xdelta;
	fract = param;
	if (ydelta > 0)
	{
		write(1, "UP\n", 3);
		// change shift.y to change map and zoom.
	}	
	else if (ydelta < 0)
	{
		write(1, "DOWN\n", 5);
		// change shift.y to change map and zoom.
	}	
	
	// code to add zoom in, rescaling the map again with the function. TODO
	// How to rescale dynamically without the fifth parameter and added 0? struct
}

// void	close_mgmt()
// {
// 	// When you click krizek free everything and close it. Easy! TODO
// }

// Here I will initialize all hooks
void	init_hooks_and_events(t_fractal *fract)
{
	mlx_key_hook(fract->mlx_cnct, &keys_mgmt, fract);
	mlx_scroll_hook(fract->mlx_cnct, &scroll_mgmt, fract->mlx_cnct);
//	mlx_close_hook(fract->mlx_cnct, &close_mgmt, fract->mlx_cnct);
//	mlx_cursor_hook(fract->mlx_cnct, &cursor_mgmt, fract->mlx_cnct); // for bonus zooming
//	mlx_hook() // What is it and how to use it? ->-> for the cursor zooming?
//	mlx_mouse_hook() // Or maybe this one for the zooming bonus?
// 	hook for pressing/clicking to change between different color schemes.
}

// init for MLX, events, hooks data TODO
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

// Nice hook function for moving, but useless.... Schade her profesor
// void	ft_move(void *param)
// {
// 	t_fractal	*fract;

// 	fract = param;
// 	if (mlx_is_key_down(fract->mlx_cnct, MLX_KEY_UP))
// 	{
// 		fract->shift.y -= 0.2;
// 		rndr_fract(fract);
// 	}	
// 	if (mlx_is_key_down(fract->mlx_cnct, MLX_KEY_DOWN))
// 	{
// 		fract->shift.y += 0.2;
// 		rndr_fract(fract);
// 	}			
// 	if (mlx_is_key_down(fract->mlx_cnct, MLX_KEY_LEFT))
// 	{
// 		fract->shift.x += 0.2;
// 		rndr_fract(fract);
// 	}	
// 	if (mlx_is_key_down(fract->mlx_cnct, MLX_KEY_RIGHT))
// 	{
// 		fract->shift.x -= 0.2;
// 		rndr_fract(fract);
// 	}	
	
// }

// Here I set values to all important stuff. Set up sub-functions.
void	data_init(t_fractal *fract, char *argv)
{
	// set random stuff
	fract->max_iter = 70;
	fract->name = argv;
	// set map_x/y
	fract->map_x.old.min = 0;
	fract->map_x.old.max = WIDTH;
	fract->map_x.new.min = -2.5;
	fract->map_x.new.max = 1.1;
	fract->map_y.old.min = 0;
	fract->map_y.old.max = HEIGHT;	
	fract->map_y.new.min = 1.8;
	fract->map_y.new.max = -1.8;
	// set shift.x/y
	fract->shift.x = 0.0;
	fract->shift.y = 0.0;
	// set color set 1
	fract->color.old.min = 0;
	fract->color.old.max = fract->max_iter;
	fract->color.new.min = PSYC_LASER_YELLOW;
	fract->color.new.max = MAGENTA;
	

	printf("%s\n", argv); // just a test and let's see
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