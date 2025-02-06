/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:15:11 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/06 02:36:36 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/fractal.h"

double	divergent_value(t_complex z)
{
	double	result;
	
	result = z.real + z.i;
	return (result);
}

t_complex	complex_squared(t_complex z)
{
	double	temp_real;

	temp_real = (z.real * z.real) - (z.i * z.i);
	z.i = 2 * z.real * z.i;
	z.real = temp_real;

	return (z);
}

t_complex	complex_addition(t_complex z, t_complex c)
{
	t_complex	result;
	
	result.real = z.real + c.real;
	result.i = z.i + c.i;
	return (result);
}
