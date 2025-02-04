/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:21:27 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/04 17:41:59 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DO NOW: Fractal (Mandelbrot part) video by Oceano

// fractol struct and keep adding more if needed.
// math_utils.c -> addition, squaring, escape value 4(Pythagoras)
// Mandelbrot & Julia (different Julias with diff input values)
// Mouse wheel zooms in & out almost infinitively.
// Use diff colours for diff iterations of fractals.
// Window management must be smooth (disable it??)
// ESC and "X" must exit smoothly.
// MiniLibX(MLX42) use of images is necessary.

// BONUS:
// More parameters from command line if needed.
// Extra fractal (third)
// Zoom follows the cursor (hook to center on cursor's position?)
// Moving the view by pressing arrow keys. (similar to test "test")
// Make the color range shift (ask Zuzi).
// Change number of iterations with a + -.

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

#include "include/fractal.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	
	// Checks for correct arguments
	if (!((argc == 2 && ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
	|| (argc == 4 && ft_strncmp(argv[1], "Julia", 6) == 0)))
	{
		ft_printf("incorrect argument(s)\n\ttype \"Mandelbrot\""
		"\n     or\ttype \"Julia\", value 1 and value 2\n");
		return (EXIT_FAILURE);
	}
	// Initialization of the MLX and the window stuff
	init_fract(&fractal);
	
	// Rendering of the image


	mlx_loop(fractal.mlx_cnct);
	return (EXIT_SUCCESS);
}

// Calculate the math yourself -> z^2 + c -> almost // DONE
// typedef struct for s_complex -> real and imaginary with doubles // DONE
// Start up checks. // DONE
// Put image onto window // DONE
// key hook to print pressed key // DONE
// test case for MLX42, not working...
// setup MLX42 correctly, MLX42.h and make and make clean // DONE
// Have window on screen // DONE