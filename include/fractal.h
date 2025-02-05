/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:17:58 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/05 20:19:18 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# define WIDTH 500
# define HEIGHT 500

// HEADERS

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>
# include "MLX42/MLX42.h"
# include "MLX42/MLX42_Int.h"
# include "libft.h"

// STRUCTS

typedef struct s_complex
{
	double	real;
	double	i;
} 			t_complex;

typedef struct s_image // TODO
{
	void	*image;
	


	
}			t_image;

typedef struct s_fractal
{
	void		*mlx_cnct;
	void		*image;
	t_complex	z;
	t_complex	c;
	
	
}			t_fractal;



// FTS

// HELPER >> DELETE LATER

#endif