/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:01:24 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/14 16:00:09 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render/render.h"
#include "minimap.h"

static void draw_view_cone(t_game *game, t_mmap mm)
{
	int		   i;
	int		   j;
	int		   col;
	int		   map_x;
	int		   map_y;
	t_vector_d next_pixel;

	i = -1;
	j = -MM_VIEW_CONE / 2;
	while (++j < MM_VIEW_CONE / 2)
	{
		next_pixel.x = mm.center.x + game->player.plane.x * j;
		next_pixel.y = mm.center.y - game->player.plane.y * j;
		while (++i < MM_VIEW_CONE)
		{
			next_pixel.x += game->player.dir.x;
			next_pixel.y -= game->player.dir.y;
			if (i * .5 < iabs(j))
				continue;
			map_x = (int)next_pixel.x - MM_MARGIN;
			map_y = SCREEN_HEIGHT - (int)next_pixel.y - MM_MARGIN;
			col	  = mm.map[map_y][map_x];
			// printf("C: %d/%d\n", map_x, map_y);
			pixel_put(&game->img, (int)next_pixel.x, (int)next_pixel.y, col);
		}
		i = -1;
	}
}

void draw_player(t_game *game, t_mmap mm)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < 5)
	{
		while (i++ < 5)
			pixel_put(&game->img, mm.center.x + i, mm.center.y + j, C_NEON_YELLOW);
		j++;
		i = 0;
	}
	mm.center.x += 3;
	mm.center.y += 3;
	draw_view_cone(game, mm);
}
