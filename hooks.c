/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:44:40 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/11 20:01:54 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

// All key hooks, including hook to close after pressing ESC.
void	keys_mgmt(mlx_key_data_t keydata, void *param)
{
	t_fractal *fract = param;
	
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		write(1, "ESCAPED\n", 8);
		mlx_close_window(fract->mlx_cnct);
		mlx_delete_image(fract->mlx_cnct, fract->img);
		mlx_terminate(fract->mlx_cnct);
		exit(EXIT_SUCCESS);
	}
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		fract->shift.y -= fract->zoom_y.old / 8;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		fract->shift.y += fract->zoom_y.old / 8;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		fract->shift.x -= fract->zoom_x.old / 8;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		fract->shift.x += fract->zoom_x.old / 8;
	else if (keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS)
		fract->max_iter += 7;
	else if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action == MLX_PRESS)
		fract->max_iter -= 7;
	if (keydata.key == MLX_KEY_KP_1 && keydata.action == MLX_PRESS)
	{
		fract->color.new.min = BLACK;
		fract->color.new.max = WHITE;
	}
	if (keydata.key == MLX_KEY_KP_2 && keydata.action == MLX_PRESS)
	{
		fract->color.new.min = YELLOW;
		fract->color.new.max = MAGENTA;
	}
	if (keydata.key == MLX_KEY_KP_3 && keydata.action == MLX_PRESS)
	{
		fract->color.new.min = PSYC_SHOCKING_LIME;
		fract->color.new.max = PSYC_LASER_YELLOW;
	}
	rndr_fract(fract);
}

// typedef void (*mlx_scrollfunc)(double xdelta, double ydelta, void* param);
void	scroll_mgmt(double xdelta, double ydelta, void *param)
{
	t_fractal	*fract;
	double 		zoom;

	fract = param;
	(void)xdelta;
	if (ydelta > 0)
		zoom = 0.80;
	if (ydelta < 0)
		zoom = 1.20;
	// fract->mouse.x is a pointer and # from 0 to 800.
	mlx_get_mouse_pos(fract->mlx_cnct, &fract->mouse.x, &fract->mouse.y);
	fract->zoom_x.center = map(fract->mouse.x, fract->map_x.old, fract->map_x.new); // mouse X
	fract->zoom_y.center = map(fract->mouse.y, fract->map_y.old, fract->map_y.new); // mouse Y
	// calculate x
//	fract->zoom_x.center = (fract->map_x.new.min + fract->map_x.new.max) / 2;
	fract->zoom_x.old = fract->map_x.new.max - fract->map_x.new.min;
	fract->zoom_x.new = fract->zoom_x.old * zoom;
	// set new x
	fract->map_x.new.min = fract->zoom_x.center - fract->zoom_x.new / 2;
	fract->map_x.new.max = fract->zoom_x.center + fract->zoom_x.new / 2;
	// calculate y
//	fract->zoom_y.center = (fract->map_y.new.min + fract->map_y.new.max) / 2;
	fract->zoom_y.old = fract->map_y.new.max - fract->map_y.new.min;
	fract->zoom_y.new = fract->zoom_y.old * zoom;
	// set new y
	fract->map_y.new.min = fract->zoom_y.center - fract->zoom_y.new / 2;
	fract->map_y.new.max = fract->zoom_y.center + fract->zoom_y.new / 2;

	rndr_fract(fract);
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
