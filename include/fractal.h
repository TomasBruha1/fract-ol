/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:17:58 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/06 03:18:05 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

// HEADERS

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>
# include "MLX42/MLX42.h"
# include "MLX42/MLX42_Int.h"
# include "libft.h"

// OTHER

# define WIDTH 500
# define HEIGHT 500

// STRUCTS

// real and imaginary values
typedef struct s_complex
{
	double	real;
	double	i;
} 			t_complex;

// core struct where I keep everything
typedef struct s_fractal
{
	mlx_t		*mlx_cnct;
	mlx_image_t	*img;
	char		*name;
	int			iterations; // so I can change it via hook and pass the fract
	t_complex	z; // why?
	t_complex	c; // why?
}			t_fractal;

// FTS

// math.c
double	divergent_value(t_complex z);
t_complex	complex_squared(t_complex z);
t_complex	complex_addition(t_complex z, t_complex c);

// rendering.c
void    rndr_fract(t_fractal *fractol);

// utils.c
void    error_msg_malloc();

#endif
