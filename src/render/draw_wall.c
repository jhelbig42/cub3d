/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:35:01 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/06 16:33:58 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_wall_x(t_game *game, int x, int wall_height)
{
	int	y;
	int	top;
	//int	tex_x;
	//int	tex_y;
	//int pos;

	//tex_x = (game->north.width / SCREEN_WIDTH) * x;
	y = game->horizont - wall_height / 2;
	top = game->horizont + wall_height / 2;
	while (y++ < top)
	{
		//tex_y = (game->north.height / wall_height) * y;
		//pos = (tex_y * game->north.size_line + tex_x * (game->north.bpp / 8));
		//pixel_put(&game->img, x + 1, y, *(unsigned int *)game->north.addr + pos);
		pixel_put(&game->img, x + 1, y, C_NEON_YELLOW);
	}
}
