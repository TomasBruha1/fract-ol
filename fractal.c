/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:21:27 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/03 13:03:16 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractal.h"
#define WIDTH 500
#define HEIGHT 500

// DO NOW: test case for MLX42
// put image onto window
// put pixels (Pollock) onto my window
// key hook to print pressed key
// Mandelbrot video by Oceano

// FUNCTIONs
// mlx_new_image - creates a new blank image. // buffer probably
// mlx_image_to_window - It will put buffered image to a window.
// mlx_terminate() - It will terminate the mlx connection
//

int	main(void)
{
	void	*mlx;
//	void	*mlx_window;
	
	mlx = mlx_init(WIDTH, HEIGHT, "fractal starter", false);
//	mlx_window = mlx_new_window();
	mlx_loop(mlx);
	return (0);
}


// setup MLX42 correctly, MLX42.h and make and make clean // DONE
// Have window on screen // DONE