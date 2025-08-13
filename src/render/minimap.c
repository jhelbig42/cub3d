/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:05:16 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/12 11:23:45 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#define MM_ZOOM 10

static void	reset_minimap(t_game *game)
{
	int	x;
	int	y;

	x = MM_MARGIN - 1;
	y = MM_MARGIN;
	while (y++ < MM_MARGIN + MM_HEIGHT)
	{
		while (x++ < MM_MARGIN + MM_WIDTH)
		{
			pixel_put(&game->img, x, SCREEN_HEIGHT - y, 0);
		}
		x = MM_MARGIN - 1;
	}
}

static void	draw_wall_elmt(t_img img, int x, int y)
{
	t_vector_i	map_coord;
	int			i;
	int			j;

	map_coord.x = MM_MARGIN + (x * MM_ZOOM);
	map_coord.y = SCREEN_HEIGHT - MM_MARGIN - MM_HEIGHT + (y * MM_ZOOM);
	i = map_coord.x;
	j = map_coord.y;
	while (j > map_coord.y - MM_ZOOM)
	{
		while (i < map_coord.x + MM_ZOOM)
		{
			pixel_put(&img, i, j, C_NEON_BLUE);
			i++;
		}
		j--;
		i = map_coord.x;
	}
}

void	draw_player(t_img img)
{
	t_vector_i	mm_tl;
	int			i;
	int			j;

	mm_tl.x = MM_MARGIN + MM_WIDTH / 2 + 3;
	mm_tl.y = SCREEN_HEIGHT - MM_MARGIN - MM_HEIGHT / 2 - 3;
	i = 0;
	j = 0;
	while (j < 5)
	{
		while (i < 5)
		{
			pixel_put(&img, mm_tl.x + i, mm_tl.y + j, C_NEON_YELLOW);
			i++;
		}
		j++;
		i = 0;
	}
}

void	draw_minimap(t_game *game)
{
	int			x;
	int			y;
	t_vector_i	p_pos;
	t_vector_i	mm_pos;
	t_vector_i	mm_dim;

	reset_minimap(game);
	mm_dim.x = MM_WIDTH / MM_ZOOM;
	mm_dim.y = MM_HEIGHT / MM_ZOOM;
	p_pos.x = (int)game->player.pos.x;
	p_pos.y = (int)game->player.pos.y;
	mm_pos.x = p_pos.x - mm_dim.x / 2;
	mm_pos.y = p_pos.y - mm_dim.y / 2;
	x = 0;
	y = 0;
	while (y < mm_dim.y)
	{
		while (x < mm_dim.x)
		{
			if (mm_pos.x >= 0 && mm_pos.x < game->map.width
				&& mm_pos.y >= 0 && mm_pos.y < game->map.height
				&& game->map.map[mm_pos.y][mm_pos.x])
				draw_wall_elmt(game->img, x, mm_dim.y - y);
			x++;
			mm_pos.x++;
		}
		y++;
		mm_pos.y++;
		x = 0;
		mm_pos.x = p_pos.x - mm_dim.x / 2;
	}
	draw_player(game->img);
}
