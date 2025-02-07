/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:21:27 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/07 11:48:47 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// DO NOW NOW: Add hooks for arrow moving.
// DO NOW: Fractal (Mandelbrot part) video by Oceano

//
// Update "rescaling" and rm fifth argument.
// Mandelbrot & Julia (different Julias with diff input values)
// Mouse wheel zooms in & out almost infinitively.
// Use diff colours for diff iterations of fractals.
// Window management must be smooth, resizing etc.
// ESC and "X" must exit smoothly.
// Check all fts and correct them in *.h.
// MiniLibX(MLX42) use of images is necessary. -> What does this mean??
// Check for fractol vs fractal and make it right!!

// BONUS:
// More parameters from command line if needed.
// Extra fractal (third)
// Zoom follows the cursor (hook to center on cursor's position?)
// Moving the view by pressing arrow keys. (similar to test "test")
// Make the color range shift (ask Zuzi).
// Change number of iterations with a + -. Due it via hooks in fract

// hook to close after pressing ESC
void	ft_escape(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		// Check which leaks are OK and which not with someone.
		write(1, "ESCAPED\n", 8);
		mlx_close_window(param);
		mlx_terminate(param);
		exit(EXIT_SUCCESS);
	}
}

// Here I will initialize all hooks
void	init_hooks(t_fractal *fract)
{
	mlx_key_hook(fract->mlx_cnct, &ft_escape, fract->mlx_cnct);
	//	next hooks to implement here
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

	init_hooks(fract);
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
	
	fract.name = argv[1];
	fract.iter_count = 250;
	// initialization	 of the MLX and the image stuff
	init_fract(&fract);
	// Rendering of the image, adding pixels.
	rndr_fract(&fract);
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
// mlx_loop() - It will keep the window openn, infinite loop.
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