/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:44:40 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/12 23:35:35 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	resize_mgmt(int32_t width, int32_t height, void* param)
{
	t_fractal *fract;

	fract = param;
	fract->side_x = width;
	fract->side_y = height;
	fract->img = mlx_new_image(fract->mlx_cnct, (uint32_t)width, (uint32_t)height);
	rndr_fract(fract);
}

void	color_and_iter(mlx_key_data_t keydata, t_fractal *fract)
{
	if (keydata.key == MLX_KEY_KP_1 && keydata.action == MLX_PRESS)
	{
		fract->color.new.min = BLACK;
		fract->color.new.max = WHITE;
	}
	else if (keydata.key == MLX_KEY_KP_2 && keydata.action == MLX_PRESS)
	{
		fract->color.new.min = YELLOW;
		fract->color.new.max = MAGENTA;
	}
	else if (keydata.key == MLX_KEY_KP_3 && keydata.action == MLX_PRESS)
	{
		fract->color.new.min = PSYC_SHOCKING_LIME;
		fract->color.new.max = PSYC_LASER_YELLOW;
	}
	else if (keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS)
		fract->max_iter += 7;
	else if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action == MLX_PRESS)
		fract->max_iter -= 7;
}

// All key hooks, including hook to close after pressing ESC.
void	keys_mgmt(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fract;

	fract = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		write(1, "BYE fractal\n", 12);
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
	else if (keydata.key == MLX_KEY_KP_1 || keydata.key == MLX_KEY_KP_2
		|| keydata.key == MLX_KEY_KP_3 || keydata.key == MLX_KEY_KP_ADD
		|| keydata.key == MLX_KEY_KP_SUBTRACT)
		color_and_iter(keydata, fract);
	rndr_fract(fract);
}

// typedef void (*mlx_scrollfunc)(double xdelta, double ydelta, void* param);
void	scroll_mgmt(double xdelta, double ydelta, void *param)
{
	t_fractal	*fract;
	double		zoom;

	fract = param;
	(void)xdelta;
	if (ydelta > 0)
		zoom = 0.80;
	if (ydelta < 0)
		zoom = 1.20;
	mlx_get_mouse_pos(fract->mlx_cnct, &fract->mouse.x, &fract->mouse.y);
	fract->zoom_x.center = map(fract->mouse.x,
			fract->map_x.old, fract->map_x.new);
	fract->zoom_y.center = map(fract->mouse.y,
			fract->map_y.old, fract->map_y.new);
	fract->zoom_x.old = fract->map_x.new.max - fract->map_x.new.min;
	fract->zoom_x.new = fract->zoom_x.old * zoom;
	fract->map_x.new.min = fract->zoom_x.center - fract->zoom_x.new / 2;
	fract->map_x.new.max = fract->zoom_x.center + fract->zoom_x.new / 2;
	fract->zoom_y.old = fract->map_y.new.max - fract->map_y.new.min;
	fract->zoom_y.new = fract->zoom_y.old * zoom;
	fract->map_y.new.min = fract->zoom_y.center - fract->zoom_y.new / 2;
	fract->map_y.new.max = fract->zoom_y.center + fract->zoom_y.new / 2;
	rndr_fract(fract);
}

void	close_mgmt(void *param)
{
	t_fractal	*fract;

	fract = param;
	write(1, "BYE fractal\n", 12);
	mlx_close_window(fract->mlx_cnct);
	mlx_delete_image(fract->mlx_cnct, fract->img);
	mlx_terminate(fract->mlx_cnct);
	exit(EXIT_SUCCESS);
}
