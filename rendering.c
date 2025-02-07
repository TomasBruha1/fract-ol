/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:02:22 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/07 11:43:08 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_mgmt(int x, int y, t_fractal *fract)
{
	t_complex	z;
	t_complex	c;
	int			i;
	uint32_t	color;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = rescaling(x, 0, WIDTH, -2.5, 1.1);
	c.y = rescaling(y, 0, HEIGHT, 1.8, -1.8);
	while (i < fract->iter_count)
	{
		z = complex_add(complex_squared(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = rescaling(i, 0, fract->iter_count, PSYC_LASER_YELLOW, RED);
			if (i < 9)
				color = WHITE;
			mlx_put_pixel(fract->img, x, y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(fract->img, x, y, PSYC_LASER_YELLOW);
}

// Iteration through the whole img and handling pixels in pixel_mgmt.
// Putting img to window when everything is done.
void    rndr_fract(t_fractal *fract)
{
	int x;
	int y;

	y = 0;
	while (y++ < WIDTH)
	{
		x = 0;
		while (x++ < HEIGHT)
		{
			pixel_mgmt(x, y, fract);
		}
	}
	if (mlx_image_to_window(fract->mlx_cnct, fract->img, 0, 0) < 0)
		perror("img to window failed\n");
}
