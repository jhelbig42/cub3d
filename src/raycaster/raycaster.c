/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:47:59 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/31 16:33:38 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

// set default vals and calculate,vector of current ray
t_ray init_ray(t_player p, int x)
{
	t_ray ray;

	ray.hit		 = false;
	ray.map.x	 = (int)p.pos.x;
	ray.map.y	 = (int)p.pos.y;
	ray.side	 = -1;
	ray.delta.x	 = 1e30;
	ray.delta.y	 = 1e30;
	ray.step.x	 = 1;
	ray.step.y	 = 1;
	ray.camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray.dir.x	 = p.dir.x + p.plane.x * ray.camera_x;
	ray.dir.y	 = p.dir.y + p.plane.y * ray.camera_x;
	return (ray);
}

// Define the ratio between x/y vectore, the step direction,
// and distance to first square intersection
t_ray get_delta_step_dist(t_ray ray, t_player p)
{
	if (ray.dir.x != 0)
		ray.delta.x = fabs(1 / ray.dir.x);
	if (ray.dir.y != 0)
		ray.delta.y = fabs(1 / ray.dir.y);
	if (ray.dir.x < 0)
	{
		ray.step.x		= -1;
		ray.side_dist.x = (p.pos.x - ray.map.x) * ray.delta.x;
	}
	else
		ray.side_dist.x = (ray.map.x + 1.0 - p.pos.x) * ray.delta.x;
	if (ray.dir.y < 0)
	{
		ray.step.y		= -1;
		ray.side_dist.y = (p.pos.y - ray.map.y) * ray.delta.y;
	}
	else
		ray.side_dist.y = (ray.map.y + 1.0 - p.pos.y) * ray.delta.y;
	return (ray);
}

// DDA - Digital Differential Analysis
// Jump one square further until hit a target
// return wall height
int dda(t_game *game, t_ray ray)
{
	double perp_wall_dist;

	while (ray.hit == 0)
	{
		if (ray.side_dist.x < ray.side_dist.y)
		{
			ray.side_dist.x += ray.delta.x;
			ray.map.x += ray.step.x;
			ray.side = 0;
		}
		else
		{
			ray.side_dist.y += ray.delta.y;
			ray.map.y += ray.step.y;
			ray.side = 1;
		}
		if (game->map.map[ray.map.x][ray.map.y] > 0)
			ray.hit = 1;
	}
	if (ray.side == 0)
		perp_wall_dist = (ray.side_dist.x - ray.delta.x);
	else
		perp_wall_dist = (ray.side_dist.y - ray.delta.y);
	return ((int)(SCREEN_HEIGHT / perp_wall_dist));
}

void raycaster(t_game *game)
{
	int		 x;
	int		 height;
	t_ray	 ray;
	t_player p;

	p = game->player;
	x = -1;
	while (++x <= SCREEN_WIDTH)
	{
		ray	   = init_ray(p, x);
		ray	   = get_delta_step_dist(ray, p);
		height = dda(game, ray);
		draw_wall_x(game->img, x, height);
	}
}
