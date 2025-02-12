/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:17:58 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/13 00:41:45 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// HEADERS

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>
# include "MLX42/MLX42.h"
# include "MLX42/MLX42_Int.h"
# include "libft.h"
# include "fractol.h"

// COLORS

# define PSYC_HOT_PINK       0xFF69B4FF
# define PSYC_NEON_GREEN     0x39FF14FF
# define PSYC_ELECTRIC_BLUE  0x7DF9FFFF
# define PSYC_NEON_ORANGE    0xFFA343FF
# define PSYC_VIBRANT_PURPLE 0xAD00FFFF
# define PSYC_SHOCKING_LIME  0xCCFF00FF
# define PSYC_NEON_CYAN      0x00FFFFFF
# define PSYC_LASER_YELLOW   0xFFFF00FF
# define PSYC_ULTRA_MAGENTA  0xFF00FFFF
# define PSYC_RADIANT_RED    0xFF0000FF

# define RED            0xFF0000FF  // Pure red
# define ORANGERED      0xFF4500FF  // A vivid red-orange
# define ORANGE         0xFFA500FF  // Standard orange
# define GOLD           0xFFD700FF  // Golden yellow-orange
# define YELLOW         0xFFFF00FF  // Bright yellow
# define CHARTREUSE     0x7FFF00FF  // Yellowish green
# define LIME           0x00FF00FF  // Pure, bright green
# define SPRING_GREEN   0x00FF7FFF  // Green with a touch of blue
# define AQUAMARINE     0x7FFFD4FF  // Soft turquoise-green
# define CYAN           0x00FFFFFF  // Pure cyan
# define SKY_BLUE       0x87CEEBFF  // Light blue, like a clear sky
# define DEEP_SKY_BLUE  0x00BFFFFF  // Rich, vivid blue
# define DODGER_BLUE    0x1E90FFFF  // Bright blue with a slight edge
# define BLUE           0x0000FFFF  // Pure blue
# define MEDIUM_BLUE    0x0000CDFF  // A slightly darker blue
# define INDIGO         0x4B0082FF  // Deep indigo, bridging blue and violet
# define VIOLET       	0xEE82EEFF  // Soft violet
# define PURPLE       	0x800080FF  // Classic purple
# define MAGENTA      	0xFF00FFFF  // Bold, bright magenta
# define DEEP_PINK  	0xFF1493FF  // Rich pink leaning toward red
# define BLACK			0x000000FF  // Blackish black
# define WHITE			0xFFFFFFFF  // Whitening white
# define BRITISH		0xFCBE11FF	// British Standard subtitle color

// DIMENSIONS

# define WIDTH 800
# define HEIGHT 800

// STRUCTS

// real and imaginary values
typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

// old/new for map function
typedef struct s_limits
{
	double	min;
	double	max;
}			t_limits;

// to pass values for colors
typedef struct s_map
{
	t_limits	old;
	t_limits	new;
}			t_map;

typedef struct s_zoom
{
	double	center;
	double	old;
	double	new;
}			t_zoom;

typedef struct s_mouse
{
	int32_t	x;
	int32_t	y;
}			t_mouse;

// core struct where I keep everything
typedef struct s_fractal
{
	mlx_t		*mlx_cnct;
	mlx_image_t	*img;
	char		*name;
	int			max_iter;
	t_complex	shift;
	t_map		color;
	t_map		map_x;
	t_map		map_y;
	t_zoom		zoom_x;
	t_zoom		zoom_y;
	t_mouse		mouse;
	int			julia;
	t_complex	julia_c;
	int32_t		side_x;
	int32_t		side_y;
}			t_fractal;

// FTS

// fractol.c
void		init_hooks_and_events(t_fractal *fract);
void		set_sets(t_fractal *fract, char **argv);
void		data_init(t_fractal *fract, char **argv);
void		init_fract(t_fractal *fract);

// hooks.c
void		keys_mgmt(mlx_key_data_t keydata, void *param);
void		scroll_mgmt(double xdelta, double ydelta, void *param);
void		close_mgmt(void *param);
void		resize_mgmt(int32_t width, int32_t height, void *param);
void		color_and_iter(mlx_key_data_t keydata, t_fractal *fract);

// rendering.c
void		rndr_fract(t_fractal *fractol);
void		calc_mandel(int x, int y, t_fractal *fract);
void		calc_julia(int x, int y, t_fractal *fract);

// math.c
t_complex	complex_squared(t_complex z);
t_complex	complex_add(t_complex z, t_complex c);
double		map(double nbr, t_limits old, t_limits new);

// utils.c
void		error_msg_malloc(void);
void		set_julias(t_fractal *fract);

#endif
