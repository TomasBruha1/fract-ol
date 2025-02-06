/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:17:58 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/06 21:45:25 by tbruha           ###   ########.fr       */
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

// COLORS

#define PSYC_HOT_PINK       0xFF69B4FF  // R=FF, G=69, B=B4, A=FF
#define PSYC_NEON_GREEN     0x39FF14FF  // R=39, G=FF, B=14, A=FF
#define PSYC_ELECTRIC_BLUE  0x7DF9FFFF  // R=7D, G=F9, B=FF, A=FF
#define PSYC_NEON_ORANGE    0xFFA343FF  // R=FF, G=A3, B=43, A=FF
#define PSYC_VIBRANT_PURPLE 0xAD00FFFF  // R=AD, G=00, B=FF, A=FF
#define PSYC_SHOCKING_LIME  0xCCFF00FF  // R=CC, G=FF, B=00, A=FF
#define PSYC_NEON_CYAN      0x00FFFFFF  // R=00, G=FF, B=FF, A=FF
#define PSYC_LASER_YELLOW   0xFFFF00FF  // R=FF, G=FF, B=00, A=FF
#define PSYC_ULTRA_MAGENTA  0xFF00FFFF  // R=FF, G=00, B=FF, A=FF
#define PSYC_RADIANT_RED    0xFF0000FF  // R=FF, G=00, B=00, A=FF

#define RED             0xFF0000FF  // Pure red
#define ORANGERED       0xFF4500FF  // A vivid red-orange
#define ORANGE          0xFFA500FF  // Standard orange
#define GOLD            0xFFD700FF  // Golden yellow-orange
#define YELLOW          0xFFFF00FF  // Bright yellow
#define CHARTREUSE      0x7FFF00FF  // Yellowish green
#define LIME            0x00FF00FF  // Pure, bright green
#define SPRING_GREEN    0x00FF7FFF  // Green with a touch of blue
#define AQUAMARINE      0x7FFFD4FF  // Soft turquoise-green
#define CYAN            0x00FFFFFF  // Pure cyan
#define SKY_BLUE        0x87CEEBFF  // Light blue, like a clear sky
#define DEEP_SKY_BLUE   0x00BFFFFF  // Rich, vivid blue
#define DODGER_BLUE     0x1E90FFFF  // Bright blue with a slight edge
#define BLUE            0x0000FFFF  // Pure blue
#define MEDIUM_BLUE     0x0000CDFF  // A slightly darker blue
#define INDIGO          0x4B0082FF  // Deep indigo, bridging blue and violet
#define VIOLET          0xEE82EEFF  // Soft violet
#define PURPLE          0x800080FF  // Classic purple
#define MAGENTA         0xFF00FFFF  // Bold, bright magenta
#define DEEP_PINK       0xFF1493FF  // Rich pink leaning toward red

// DIMENSIONS

# define WIDTH 500
# define HEIGHT 500

// STRUCTS

// real and imaginary values
typedef struct s_complex
{
	double	x;
	double	y;
} 			t_complex;

// core struct where I keep everything
typedef struct s_fractal
{
	mlx_t		*mlx_cnct;
	mlx_image_t	*img;
	char		*name;
	int			iter_count; // so I can change it via hook and pass the fract
}			t_fractal;

// FTS

// math.c
t_complex	complex_squared(t_complex z);
t_complex	complex_add(t_complex z, t_complex c);
double	rescaling(double nbr, double old_min, double old_max,
double new_min, double new_max);

// rendering.c
void    rndr_fract(t_fractal *fractol);

// utils.c
void    error_msg_malloc();

#endif
