/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:01:24 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/20 11:29:40 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render/render.h"
#include "minimap.h"

static void	draw_view_cone(t_game *game, t_mmap mm)
{
	int			i;
	int			j;
	int			col;
	int			map_x;
	int			map_y;
	t_vector_d	next_pixel;

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
				continue ;
			map_x = (int)next_pixel.x - MM_MARGIN;
			map_y = SCREEN_HEIGHT - (int)next_pixel.y - MM_MARGIN;
			col = mm.map[map_y][map_x];
			pixel_put(&game->img, (int)next_pixel.x, (int)next_pixel.y, col);
		}
		i = -1;
	}
}

void	draw_player(t_game *game, t_mmap mm)
{
	int	i;
	int	j;

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

void	draw_wall_elmt(t_img img, int x, int y)
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

void	mm_add_wall_elmt(int cell_x, int cell_y, t_mmap mm)
{
	int	i;
	int	j;
	int	pix_x;
	int	pix_y;

	j = 0;

	pix_x = cell_x * MM_ZOOM + MM_ZOOM;
	pix_y = cell_y * MM_ZOOM;
	while (j < MM_ZOOM)
	{
		i = 0;
		while (i < MM_ZOOM)
		{
			if (pix_x - i >= 0 && pix_x - i < MM_WIDTH && pix_y + j >= 0 && pix_y + j < MM_HEIGHT)
				mm.map[pix_y + j][pix_x - i] = C_NEON_VIOLET;
			i++;
		}
		j++;
	}
}
