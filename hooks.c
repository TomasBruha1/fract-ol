/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:44:40 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/10 21:32:46 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

// All key hooks, including hook to close after pressing ESC.
void	keys_mgmt(mlx_key_data_t keydata, void *param)
{
	t_fractal *fract = param;
	
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		// Check which leaks are OK and which not with someone.
		write(1, "ESCAPED\n", 8);
		mlx_close_window(fract->mlx_cnct);
		mlx_delete_image(fract->mlx_cnct, fract->img);
		mlx_terminate(fract->mlx_cnct);
		exit(EXIT_SUCCESS);
	}
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		fract->shift.y -= 0.35;
	//	rndr_fract(fract);
	}
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		fract->shift.y += 0.35;
	//	rndr_fract(fract);
	}
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		fract->shift.x += 0.35;
	//	rndr_fract(fract);
	}
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		fract->shift.x -= 0.35;
	//	rndr_fract(fract);
	}
	else if (keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS)
		fract->max_iter += 10;
	else if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action == MLX_PRESS)
		fract->max_iter -= 10;
	rndr_fract(fract);
}

// typedef void (*mlx_scrollfunc)(double xdelta, double ydelta, void* param);
void	scroll_mgmt(double xdelta, double ydelta, void *param)
{
	t_fractal	*fract;
//	double 		zoom;

	fract = param;
	(void)xdelta;
	(void)ydelta;
	(void)fract;
	// if (ydelta > 0)
	// 	zoom = 0.9;
	// else if (ydelta < 0)
	// 	zoom = 1.1;
	// else
	// 	zoom = 0;
	// fract->zoom_x.center = (fract->map_x.new.min + fract->map_x.new.max) / 2;
	// fract->zoom_x.old = fract->map_x.new.max - fract->map_x.new.min;
	// fract->zoom_x.new = fract->zoom_x.old * zoom;

	// fract->map_x.new.min = fract->zoom_x.center - fract->zoom_x.new / 2;
	// fract->map_x.new.max = fract->zoom_x.center - fract->zoom_x.new / 2;

	// fract->zoom_y.center = (fract->map_y.new.min + fract->map_y.new.max) / 2;
	// fract->zoom_y.old = fract->map_y.new.max - fract->map_y.new.min;
	// fract->zoom_y.new = fract->zoom_y.old * zoom;
	
	// fract->map_y.new.min = fract->zoom_y.center - fract->zoom_y.new / 2;
	// fract->map_y.new.max = fract->zoom_y.center - fract->zoom_y.new / 2;

	rndr_fract(fract);
	// code to add zoom in, rescaling the map again with the function. TODO
}

void	close_mgmt(void *param)
{
	t_fractal   *fract;

	fract = NULL;
	fract->mlx_cnct = param;
	
	write(1, "ESCAPED\n", 8);
	mlx_close_window(fract->mlx_cnct);
	mlx_delete_image(fract->mlx_cnct, fract->img);
	mlx_terminate(fract->mlx_cnct);
	exit(EXIT_SUCCESS);
		// When you click krizek free everything and close it. Easy! TODO
}