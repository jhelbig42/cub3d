/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:35:01 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/12 10:55:17 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

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
	if (y < 0)
		y = 0;
	top = game->horizont + ray.wall_height / 2;
	if (top > SCREEN_HEIGHT)
		top = SCREEN_HEIGHT;
	// Calculate vertical step and starting texture position
	step_y = (double)ray.tex->height / ray.wall_height;
	tex_pos = (y - game->horizont + ray.wall_height / 2) * step_y;

	// Calculate texture X coordinate
	tex_x = (int)(ray.wall_x * ray.tex->width);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= ray.tex->width) 
		tex_x = ray.tex->width - 1;

	while (y < top)
	{
		tex_y = (int)tex_pos;
		if (tex_y >= ray.tex->height) 
			tex_y = ray.tex->height - 1;

		// Calculate memory position in the texture
		pos = tex_y * ray.tex->size_line + tex_x * (ray.tex->bpp / 8);

		// Draw pixel
		unsigned int color = *(unsigned int *)(ray.tex->addr + pos);
		pixel_put(&game->img, x, y, color);

		tex_pos += step_y;
		y++;
	}
}


