/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:05:16 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/14 14:02:55 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include "../render/render.h"

static int init_minimap(t_mmap *mm, t_game *game)
{
	int i = 0;

	mm->map_dim.x = MM_WIDTH / MM_ZOOM;
	mm->map_dim.y = MM_HEIGHT / MM_ZOOM;
	mm->p_pos.x	  = (int)game->player.pos.x;
	mm->p_pos.y	  = (int)game->player.pos.y;
	mm->tl.x	  = MM_MARGIN + MM_WIDTH / 2 + 3;
	mm->tl.y	  = SCREEN_HEIGHT - MM_MARGIN - MM_HEIGHT / 2 - 3;

	mm->map = malloc(MM_HEIGHT * sizeof(int *));
	if (!mm->map)
		return (1);
	while (i++ < MM_HEIGHT)
	{
		mm->map[i] = malloc(MM_WIDTH * sizeof(int));
		if (!mm->map[i])
		{
			i = 0;
			while (mm->map[i++])
				free(mm->map[i++]);
			free(mm->map);
			return (1);
		}
	}
	return (0);
}

static void reset_minimap(t_game *game, t_mmap mm)
{
	int x;
	int y;

	x = MM_MARGIN - 1;
	y = MM_MARGIN;
	while (y++ < MM_MARGIN + MM_HEIGHT)
	{
		while (x++ < MM_MARGIN + MM_WIDTH)
		{
			mm.map[y - MM_MARGIN][x - MM_MARGIN + 1] = 0;
			pixel_put(&game->img, x, SCREEN_HEIGHT - y, 0);
		}
		x = MM_MARGIN - 1;
	}
}

static void draw_wall_elmt(t_img img, int x, int y)
{
	t_vector_i map_coord;
	int		   i;
	int		   j;

	map_coord.x = MM_MARGIN + (x * MM_ZOOM);
	map_coord.y = SCREEN_HEIGHT - MM_MARGIN - MM_HEIGHT + (y * MM_ZOOM);
	i			= map_coord.x;
	j			= map_coord.y;
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

static void mm_wall_elmt(int x, int y, t_mmap mm)
{
	t_vector_i map_coord;
	int		   i;
	int		   j;

	i = map_coord.x - MM_MARGIN;
	j = map_coord.y - MM_MARGIN;
	while (j > map_coord.y - MM_ZOOM)
	{
		while (i < map_coord.x + MM_ZOOM)
		{
			mm.map[y + i][x + i] = C_NEON_VIOLET;
			i++;
		}
		j--;
		i = map_coord.x - MM_MARGIN;
	}
}

static void create_minimap(t_game *game, t_mmap mm)
{
	int		   x;
	int		   y;
	t_vector_i map_pos;

	map_pos.x = mm.p_pos.x - mm.map_dim.x / 2;
	map_pos.y = mm.p_pos.y - mm.map_dim.y / 2;
	x		  = 0;
	y		  = 0;
	while (y < mm.map_dim.y)
	{
		while (x < mm.map_dim.x)
		{
			if (map_pos.x >= 0 && map_pos.x < game->map.width && map_pos.y >= 0 && map_pos.y < game->map.height && game->map.map[map_pos.y][map_pos.x])
			{
				draw_wall_elmt(game->img, x, mm.map_dim.y - y);
				mm_wall_elmt(x, mm.map_dim.y - y, mm);
			}
			x++;
			map_pos.x++;
		}
		y++;
		map_pos.y++;
		x		  = 0;
		map_pos.x = mm.p_pos.x - mm.map_dim.x / 2;
	}
}

void draw_minimap(t_game *game)
{
	static t_mmap mm;

	if (init_minimap(&mm, game))
		return;
	reset_minimap(game, mm);
	create_minimap(game, mm);
	draw_player(game, mm);
}
