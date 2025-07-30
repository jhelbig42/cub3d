/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:47:59 by uschmidt          #+#    #+#             */
/*   Updated: 2025/07/29 16:13:50 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

//set default vals and calculate,vector of current ray
t_ray	init_ray(t_player p, int x)
{
	t_ray		ray;

	ray.hit = false;
	ray.map_x = (int)p.pos_x;
	ray.map_y = (int)p.pos_y;
	ray.side = -1; 
	ray.delta_x = 1e30;
	ray.delta_y = 1e30;
	ray.step_x = 1;
	ray.step_y = 1;
	ray.camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray.dir_x = p.dir_x + p.plane_x * ray.camera_x;
	ray.dir_y = p.dir_y + p.plane_y * ray.camera_x;
	return (ray);
}

//Define the ratio between x/y vectore, the step direction,
//and distance to first square intersection
t_ray	get_delta_step_dist(t_ray ray, t_player p)
{
	if (ray.dir_x != 0)
		ray.delta_x = fabs(1 / ray.dir_x);
	if (ray.dir_y != 0)
		ray.delta_y = fabs(1 / ray.dir_y);
	if (ray.dir_x < 0)
	{
		ray.step_x = -1;
		ray.side_dist_x = (p.pos_x - ray.map_x) * ray.delta_x;
	}
	else
		ray.side_dist_x = (ray.map_x + 1.0 - p.pos_x) * ray.delta_x;
	if (ray.dir_y < 0)
	{
		ray.step_y = -1;
		ray.side_dist_y = (p.pos_y - ray.map_y) * ray.delta_y;
	}
	else
		ray.side_dist_y = (ray.map_y + 1.0 - p.pos_y) * ray.delta_y;
	return (ray);
}

//DDA - Digital Differential Analysis
//Jump one square further until hit a target
//return wall height
int	dda(t_game *game, t_ray ray)
{
	double	perp_wall_dist;

	while (ray.hit == 0)
	{
		if (ray.side_dist_x < ray.side_dist_y)
		{
			ray.side_dist_x += ray.delta_x;
			ray.map_x += ray.step_x;
			ray.side = 0;
		}
		else
		{
			ray.side_dist_y += ray.delta_y;
			ray.map_y += ray.step_y;
			ray.side = 1;
		}
		if (game->map.map[ray.map_x][ray.map_y] > 0) 
			ray.hit = 1;
	}
	if (ray.side == 0)
		perp_wall_dist = (ray.side_dist_x - ray.delta_x);
	else
		perp_wall_dist = (ray.side_dist_y - ray.delta_y);
	return ((int)(SCREEN_HEIGHT / perp_wall_dist));
}

void	raycaster(t_game *game)
{
	int			x;
	int			height;
	t_ray		ray;
	t_player	p;

	p = game->player;
	x = -1;
	while (++x <= SCREEN_WIDTH)
	{
		ray = init_ray(p, x);
		ray = get_delta_step_dist(ray, p);
		height = dda(game, ray);
		draw_wall_x(game->img, x, height);
	}
}
