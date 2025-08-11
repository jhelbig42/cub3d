/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:35:01 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/11 13:18:26 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

/*
double	wall_x;

if (ray->side == WEST || ray->side == EAST)
	wall_x = player->pos.y + ray->prep_wall_dist * ray->ray_dir_y;
else
	wall_x = player->pos.x + ray->prep_wall_dist * ray->ray_dir_x;
wall_x -= floor(wall_x); //make it start from 0

*/

void draw_wall_x(t_game *game, t_ray ray, int x)
{
	int y;
	int top;
	double step_y;
	double tex_pos;
	int tex_y;
	int tex_x;
	int pos;

	y = game->horizont - ray.wall_height / 2;
	top = game->horizont + ray.wall_height / 2;

	// Calculate vertical step and starting texture position
	step_y = (double)game->north.height / ray.wall_height;
	tex_pos = (y - game->horizont + ray.wall_height / 2) * step_y;

	// Calculate texture X coordinate
	tex_x = (int)(ray.wall_x * game->north.width);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= game->north.width) 
		tex_x = game->north.width - 1;

	while (y < top)
	{
		tex_y = (int)tex_pos;
		if (tex_y >= game->north.height) 
			tex_y = game->north.height - 1;

		// Calculate memory position in the texture
		pos = tex_y * game->north.size_line + tex_x * (game->north.bpp / 8);

		// Draw pixel
		unsigned int color = *(unsigned int *)(game->north.addr + pos);
		pixel_put(&game->img, x, y, color);

		tex_pos += step_y;
		y++;
	}
}


