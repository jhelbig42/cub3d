/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:47:59 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/29 12:20:01 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	detect_hit(void)
{
}

void	raycaster(t_game *game)
{
	int			x;
	t_ray		ray;
	t_player	p;

	p = game->player;
	x = 0;
	while (x <= SCREEN_WIDTH)
	{
		ray.hit = false;
		ray.side = -1; 
		ray.delta_x = 1e30;
		ray.delta_y = 1e30;
		ray.camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		ray.dir_x = p.dir_x + p.plane_x * ray.camera_x;
		ray.dir_y = p.dir_y + p.plane_y * ray.camera_x;
		if (ray.dir_x != 0)
			ray.delta_x = fabs(1 / ray.dir_x);
		if (ray.dir_y != 0)
			ray.delta_y = fabs(1 / ray.dir_y);
	}
}
