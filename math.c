/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:15:11 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/06 20:56:47 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractal.h"

// Don't forget to cut the fifth parameter and init 0 in the function
double	rescaling(double nbr, double old_min, double old_max,
double new_min, double new_max)
{
	double	result;
//	int		zero;
	result = ((new_max - new_min) * (nbr - old_min)	/ (old_max - old_min) + new_min);
	return (result);	
}

t_complex	complex_squared(t_complex z)
{
	double	temp_real;

	temp_real = (z.x * z.x) - (z.y * z.y);
	z.y = 2 * z.x * z.y;
	z.x = temp_real;
	return (z);
}

t_complex	complex_add(t_complex z, t_complex c)
{
	t_complex	result;

	result.x = z.x + c.x;
	result.y = z.y + c.y;
	return (result);
}
