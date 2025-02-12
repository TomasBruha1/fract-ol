/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:03:24 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/12 22:02:32 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Error message when malloc goes berserk.
void	error_msg_malloc(void)
{
	perror("malloc error\n");
	exit(EXIT_FAILURE);
}

// Setting up different Julia set options.
void	set_julias(t_fractal *fract)
{
	if (fract->julia == 1)
	{
		fract->julia_c.x = -0.79;
		fract->julia_c.y = 0.15;
	}
	else if (fract->julia == 2)
	{
		fract->julia_c.x = -1.476;
		fract->julia_c.y = 0;
	}
	else if (fract->julia == 3)
	{
		fract->julia_c.x = 0.3;
		fract->julia_c.y = -0.01;
	}
	else if (fract->julia == 4)
	{
		fract->julia_c.x = -0.22;
		fract->julia_c.y = -0.77;
	}
	else if (fract->julia == 5)
	{
		fract->julia_c.x = 0.28;
		fract->julia_c.y = 0.008;
	}
}