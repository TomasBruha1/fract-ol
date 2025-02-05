/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:21:27 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/05 23:04:13 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

// DO NOW NOW: Fractal (Mandelbrot part) video by Oceano
// DO NOW: add checks for init part for failing.

// math_utils.c -> addition, squaring, escape value 4(Pythagoras)
// Mandelbrot & Julia (different Julias with diff input values)
// Mouse wheel zooms in & out almost infinitively.
// Use diff colours for diff iterations of fractals.
// Check and add descriptions for each function.
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

// void	rndr_fract(t_fractal *fract)
// {
// 	t_complex zz;
// 	zz.real = fract->z.real;
// }

// init for MLX, events, hooks data TODO
void	init_fract(t_fractal *fract)
{
	fract->mlx_cnct = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (fract->mlx_cnct == NULL)
		error_msg_malloc();
	fract->image->img_ptr = mlx_new_image(fract->mlx_cnct, WIDTH, HEIGHT);
	if (fract->image->img_ptr == NULL)
		error_msg_malloc();
	mlx_image_to_window(fract->mlx_cnct, fract->image->img_ptr, 0, 0);
}

static void	ft_hook(mlx_t *mlx)
{
	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	
	// checks for correct arguments
	if (!((argc == 2 && ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
	|| (argc == 4 && ft_strncmp(argv[1], "Julia", 6) == 0)))
	{
		ft_printf("incorrect argument(s)\n\ttype \"Mandelbrot\""
		"\n     or\ttype \"Julia\", value 1 and value 2\n");
		return (EXIT_FAILURE);
	}
	// initialization of the MLX and the image stuff
	init_fract(&fractal);
	
	// Rendering of the image, adding pixels.
	//rndr_fract()

	mlx_loop_hook(fractal.mlx_cnct, ft_hook, fractal.mlx_cnct);
	mlx_loop(fractal.mlx_cnct);
	mlx_terminate(fractal.mlx_cnct);
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

// fractol struct and keep adding more if needed. // DONE
// Calculate the math yourself -> z^2 + c -> almost // DONE
// typedef struct for s_complex -> real and imaginary with doubles // DONE
// Start up checks. // DONE
// Put image onto window // DONE
// key hook to print pressed key // DONE
// test case for MLX42, not working...
// setup MLX42 correctly, MLX42.h and make and make clean // DONE
// Have window on screen // DONE