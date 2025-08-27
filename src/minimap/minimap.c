/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:05:16 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/20 12:25:00 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include "../render/render.h"

static int	free_minimap(t_mmap *mm)
{
	int	i;

	i = 0;
	while (i < MM_HEIGHT)
		free(mm->map[i++]);
	free(mm->map);
	return (1);
}

static int	init_minimap(t_mmap *mm, t_game *game)
{
	int	i;

	mm->map_dim.x = MM_WIDTH / MM_ZOOM;
	mm->map_dim.y = MM_HEIGHT / MM_ZOOM;
	mm->p_pos.x = (int)game->player.pos.x;
	mm->p_pos.y = (int)game->player.pos.y;
	mm->tl.x = MM_MARGIN;
	mm->tl.y = SCREEN_HEIGHT - MM_MARGIN - MM_HEIGHT;
	mm->center.x = mm->tl.x + MM_WIDTH / 2 + 3;
	mm->center.y = SCREEN_HEIGHT - MM_MARGIN - MM_HEIGHT / 2 - 3;
	mm->map = malloc(MM_HEIGHT * sizeof(int *));
	if (!mm->map)
		return (1);
	i = -1;
	while (++i < MM_HEIGHT)
	{
		mm->map[i] = malloc(MM_WIDTH * sizeof(int));
		if (!mm->map[i])
			return (free_minimap(mm));
	}
	return (0);
}

static void	reset_minimap(t_game *game, t_mmap mm)
{
	int	x;
	int	y;

	y = 0;
	while (y < MM_HEIGHT)
	{
		x = 0;
		while (x < MM_WIDTH)
		{
			mm.map[y][x] = C_MM_SHAD;
			pixel_put(&game->img, MM_MARGIN + x,
				SCREEN_HEIGHT - (MM_MARGIN + y), 0);
			x++;
		}
		y++;
	}
}

static void	create_minimap(t_game *game, t_mmap mm)
{
	t_vector_i	coord;
	t_vector_i	map_pos;

	map_pos.y = mm.p_pos.y - mm.map_dim.y / 2;
	coord.y = 0;
	while (coord.y < mm.map_dim.y)
	{
		coord.x = 0;
		map_pos.x = mm.p_pos.x - mm.map_dim.x / 2;
		while (coord.x < mm.map_dim.x)
		{
			if (map_pos.x >= 0 && map_pos.x < game->map.width && map_pos.y >= 0
				&& map_pos.y < game->map.height
				&& game->map.map[map_pos.y][map_pos.x])
			{
				draw_wall_elmt(game->img, coord.x, mm.map_dim.y - coord.y,
					game->map.map[map_pos.y][map_pos.x]);
				mm_add_wall_elmt(coord.x, coord.y, mm);
			}
			coord.x++;
			map_pos.x++;
		}
		coord.y++;
		map_pos.y++;
	}
}

void	draw_minimap(t_game *game)
{
	static t_mmap	mm;

	if (init_minimap(&mm, game))
		return ;
	reset_minimap(game, mm);
	create_minimap(game, mm);
	draw_player(game, mm);
	free_minimap(&mm);
}
