/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:15:11 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/10 16:33:46 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Using linear interpolation getting new values aka mapping.
// NUMBER, OLD MIN, OLD MAX, NEW MIN, NEW MAX
double	map(double nbr, t_limits old, t_limits new)
{
	double	result;
	
	result = ((new.max - new.min) * (nbr - old.min)
	/ (old.max - old.min) + new.min);
	return (result);	
}

// Taking z and squaring it using real and imaginary part of the number.
t_complex	complex_squared(t_complex z)
{
	double	temp_real;

	temp_real = (z.x * z.x) - (z.y * z.y);
	z.y = 2 * z.x * z.y;
	z.x = temp_real;
	return (z);
}

// Adding real parts and imaginary parts.
t_complex	complex_add(t_complex z, t_complex c)
{
	t_complex	result;

	result.x = z.x + c.x;
	result.y = z.y + c.y;
	return (result);
}
