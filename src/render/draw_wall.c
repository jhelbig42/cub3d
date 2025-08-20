/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:35:01 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/20 13:44:04 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw(t_game *game, t_ray ray, t_line *l, int x)
{
	l->tex_y = (int)l->tex_pos;
	if (l->tex_y >= ray.tex->height) 
		l->tex_y = ray.tex->height - 1;
	l->pos = l->tex_y * ray.tex->size_line + l->tex_x * (ray.tex->bpp / 8);
	pixel_put(&game->img, x, l->y, *(unsigned int *)(ray.tex->addr + l->pos));
	l->tex_pos += l->step_y;
	l->y++;
}

void	draw_wall_x(t_game *game, t_ray ray, int x)
{
	t_line	l;

	l.y = game->horizont - ray.wall_height / 2 + (int)game->player.jump_offset;
	if (l.y < 0)
		l.y = 0;
	l.top = game->horizont + ray.wall_height / 2
		+ (int)game->player.jump_offset;
	if (l.top > SCREEN_HEIGHT)
		l.top = SCREEN_HEIGHT;
	l.step_y = (double)ray.tex->height / ray.wall_height;
	l.tex_pos = (l.y - game->horizont + ray.wall_height / 2 
			- (int)game->player.jump_offset) * l.step_y;
	l.tex_x = (int)(ray.wall_x * ray.tex->width);
	if (l.tex_x < 0)
		l.tex_x = 0;
	if (l.tex_x >= ray.tex->width) 
		l.tex_x = ray.tex->width - 1;
	while (l.y < l.top)
	{
		draw(game, ray, &l, x);
	}
}
