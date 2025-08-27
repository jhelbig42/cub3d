/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:47:59 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/27 10:33:46 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render/render.h"
#include "raycaster.h"

// set default vals and calculate,vector of current ray
t_ray	init_ray(t_player p, int x)
{
	t_ray	ray;

	ray.hit = false;
	ray.map.x = (int)p.pos.x;
	ray.map.y = (int)p.pos.y;
	ray.side = -1;
	ray.delta.x = 1e30;
	ray.delta.y = 1e30;
	ray.step.x = 1;
	ray.step.y = 1;
	ray.camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray.dir.x = p.dir.x + p.plane.x * ray.camera_x;
	ray.dir.y = p.dir.y + p.plane.y * ray.camera_x;
	return (ray);
}

// Define the ratio between x/y vectore, the step direction,
// and distance to first square intersection
t_ray	get_delta_step_dist(t_ray ray, t_player p)
{
	if (ray.dir.x != 0)
		ray.delta.x = fabs(1 / ray.dir.x);
	if (ray.dir.y != 0)
		ray.delta.y = fabs(1 / ray.dir.y);
	if (ray.dir.x < 0)
	{
		ray.step.x = -1;
		ray.side_dist.x = (p.pos.x - ray.map.x) * ray.delta.x;
	}
	else
		ray.side_dist.x = (ray.map.x + 1.0 - p.pos.x) * ray.delta.x;
	if (ray.dir.y < 0)
	{
		ray.step.y = -1;
		ray.side_dist.y = (p.pos.y - ray.map.y) * ray.delta.y;
	}
	else
		ray.side_dist.y = (ray.map.y + 1.0 - p.pos.y) * ray.delta.y;
	return (ray);
}

void	set_textures(t_game *game, t_ray *ray)
{
	double	perp_wall_dist;

	if (ray->side == 0)
	{
		if (game->map.map[ray->map.y][ray->map.x] == 2)
			ray->tex = &game->door;
		else if (game->player.pos.x > ray->map.x)
			ray->tex = &game->west;
		else
			ray->tex = &game->east;
		perp_wall_dist = (ray->side_dist.x - ray->delta.x);
		ray->wall_x = game->player.pos.y + perp_wall_dist * ray->dir.y;
	}
	else
	{
		decide_sn(game, ray);
		perp_wall_dist = (ray->side_dist.y - ray->delta.y);
		ray->wall_x = game->player.pos.x + perp_wall_dist * ray->dir.x;
	}
	if (ray->tex == &game->north || ray->tex == &game->west)
		ray->wall_x = ray->wall_x - floor(ray->wall_x);
	else
		ray->wall_x = fabs(1 - (ray->wall_x - floor(ray->wall_x)));
	ray->wall_height = (int)(SCREEN_HEIGHT / perp_wall_dist);
}

// DDA - Digital Differential Analysis
// Jump one square further until hit a target
// return wall height
void	dda(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (game->map.map[ray->map.y][ray->map.x] > 0 
			&& game->map.map[ray->map.y][ray->map.x] < 3)
			ray->hit = 1;
	}
	set_textures(game, ray);
}

void	raycaster(t_game *game)
{
	int			x;
	t_ray		ray;
	t_player	p;

	p = game->player;
	x = -1;
	while (++x <= SCREEN_WIDTH)
	{
		ray = init_ray(p, x);
		ray = get_delta_step_dist(ray, p);
		dda(game, &ray);
		draw_wall_x(game, ray, x);
	}
}
