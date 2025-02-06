/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:02:22 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/06 03:23:22 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	pixel_mgmt(int x, int y, t_fractal *fract)
{
	// map to use linear intrapolation to 500 -> 2.

	// color of the pixels based on iteration
}

void    rndr_fract(t_fractal *fract)
{
	int x;
	int y;

	(void)fract;
	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
		{
			pixel_mgmt(x, y, fract); // change name
		}
	}
	
	
}