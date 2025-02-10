/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:02:22 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/10 21:33:43 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// map the image to new x y values, counting iterations count
// adding colours to pixels based on diverging and from radius of 2.
void	pixel_mgmt(int x, int y, t_fractal *fract)
{
	t_complex	z;
	t_complex	c;
	int			i;
	uint32_t	color;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = map(x, fract->map_x.old, fract->map_x.new) + fract->shift.x; // multiply
	c.y = map(y, fract->map_y.old, fract->map_y.new) + fract->shift.y; // multiply
	while (i < fract->max_iter)
	{
		z = complex_add(complex_squared(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = map(i, fract->color.old, fract->color.new); // check math lib here
			// if (i < 2)
			// 	color = PSYC_LASER_YELLOW;
			mlx_put_pixel(fract->img, x, y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(fract->img, x, y, WHITE);
}

// Iteration through the whole img and handling pixels in pixel_mgmt.
// Putting img to window when everything is done.
void    rndr_fract(t_fractal *fract)
{
	int x;
	int y;

	y = 0;
	while (y < WIDTH)
	{
		x = 0;
		while (x < HEIGHT)
		{
			pixel_mgmt(x, y, fract);
			x++;
		}
		y++;
	}
	if (mlx_image_to_window(fract->mlx_cnct, fract->img, 0, 0) < 0)
		perror("img to window failed\n");
}
