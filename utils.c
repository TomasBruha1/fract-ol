/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:03:24 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/07 11:46:59 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Error message when malloc goes berserk.
void    error_msg_malloc()
{
	perror("malloc error\n");
	exit(EXIT_FAILURE);
}
