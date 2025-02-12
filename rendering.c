/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:02:22 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/12 23:37:58 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Fractal for burning ship imaginery and last bonus to have here.
// equation -> z = abs(z)^2+c // double fabs(double nbr)
// void		calc_ship(t_fractal *fract)

void	calc_julia(int x, int y, t_fractal *fract)
{
	t_complex	z;
	t_complex	c;
	int			i;
	uint32_t	color;

	i = 0;
	z.x = map(x, fract->map_x.old, fract->map_x.new) + fract->shift.x;
	z.y = map(y, fract->map_y.old, fract->map_y.new) + fract->shift.y;
	c.x = fract->julia_c.x;
	c.y = fract->julia_c.y;
	while (i < fract->max_iter)
	{
		z = complex_add(complex_squared(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = map(i, fract->color.old, fract->color.new);
			mlx_put_pixel(fract->img, x, y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(fract->img, x, y, WHITE);
}

// map the image to new x y values, counting iterations count
// adding colours to pixels based on diverging and from radius of 2.
void	calc_mandel(int x, int y, t_fractal *fract)
{
	t_complex	z;
	t_complex	c;
	int			i;
	uint32_t	color;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = map(x, fract->map_x.old, fract->map_x.new) + fract->shift.x;
	c.y = map(y, fract->map_y.old, fract->map_y.new) + fract->shift.y;
	while (i < fract->max_iter)
	{
		z = complex_add(complex_squared(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = map(i, fract->color.old, fract->color.new);
			if (i < 0)
				color = BLACK;
			mlx_put_pixel(fract->img, x, y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(fract->img, x, y, WHITE);
}

// Separate Mandelbor/Julia/ship here.
// Iteration through the whole img and handling pixels in pixel_mgmt.
// Putting img to window when everything is done.
void	rndr_fract(t_fractal *fract)
{
	int	x;
	int	y;

	y = 0;
	while (y < fract->side_y)
	{
		x = 0;
		while (x < fract->side_x)
		{
			if (ft_strncmp(fract->name, "Mandelbrot", 11) == 0)
				calc_mandel(x, y, fract);
			else if (ft_strncmp(fract->name, "Julia", 6) == 0)
			{
				calc_julia(x, y, fract);
			}
			x++;
		}
		y++;
	}
	if (mlx_image_to_window(fract->mlx_cnct, fract->img, 0, 0) < 0)
		perror("img to window failed\n");
}
