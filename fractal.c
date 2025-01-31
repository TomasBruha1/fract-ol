/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:21:27 by tbruha            #+#    #+#             */
/*   Updated: 2025/01/31 16:19:48 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#define WIDTH 500
#define HEIGHT 500

// DO NOW: test case for MLX42

// setup MLX42 correctly, MLX42.h and what about 

int	main(void)
{
	void	*mlx;
//	void	*mlx_window;
	
	mlx = mlx_init(WIDTH, HEIGHT, "fractal starter", false);
//	mlx_window = mlx_new_window();
	mlx_loop(mlx);
	return (0);
}

// Have window on screen // DONE