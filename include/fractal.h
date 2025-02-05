/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:17:58 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/05 22:57:20 by tbruha           ###   ########.fr       */
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

// pixels buffer
typedef struct s_img
{
	void	*img_ptr;
	char	*pxls_ptr;
	int		bite_per_pixel;
	int		endian;
	int		line_len;	
}				t_img;

// core struct where I keep everything
typedef struct s_fractal
{
	void		*mlx_cnct;
	t_img		*image;
	t_complex	z;
	t_complex	c;
	
	
}			t_fractal;

// FTS

// utils.c
void    error_msg_malloc();

#endif
