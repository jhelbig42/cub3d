/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:01:24 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/14 14:27:29 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render/render.h"
#include "minimap.h"

static void draw_view_cone(t_game *game, t_vector_i center)
{
	int		   i;
	int		   j;
	t_vector_d next_pixel;

	i = -1;
	j = -MM_VIEW_CONE / 2;
	while (++j < MM_VIEW_CONE / 2)
	{
		next_pixel.x = center.x + game->player.plane.x * j;
		next_pixel.y = center.y - game->player.plane.y * j;
		while (++i < MM_VIEW_CONE)
		{
			next_pixel.x += game->player.dir.x;
			next_pixel.y -= game->player.dir.y;
			if (i * .5 < iabs(j))
				continue;
			if ((float)random() / (float)RAND_MAX < 1.0f - (float)i / MM_VIEW_CONE)
				pixel_put(&game->img, (int)next_pixel.x, (int)next_pixel.y, C_NEON_YELLOW | 0xAAAAAAAA);
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
			pixel_put(&game->img, mm.tl.x + i, mm.tl.y + j, C_NEON_YELLOW);
		j++;
		i = 0;
	}
	mm.tl.x += 3;
	mm.tl.y += 3;
	draw_view_cone(game, mm.tl);
}
