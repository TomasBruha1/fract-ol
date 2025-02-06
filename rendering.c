/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:02:22 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/06 21:46:59 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	pixel_mgmt(int x, int y, t_fractal *fract)
{
	t_complex	z;
	t_complex	c;
	int			i;
	uint32_t	color;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = rescaling(x, 0, WIDTH, -2, 2);
	c.y = rescaling(y, 0, HEIGHT, 2, -2);
	fract->iter_count = 5;
	while (i < fract->iter_count)
	{
		z = complex_add(complex_squared(z), c);
		
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			// calculate color here and pass it to mlx_put_pixel.
			color = PSYC_ELECTRIC_BLUE;
			mlx_put_pixel(fract->img, x, y, color);
			return ;
		}
		i++;
	}
	// color of the pixels based on iteration
	// while (z.x) * (z.x) + (z.y) * (z.y) < 4 do something...
}

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
