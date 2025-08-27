/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:23:33 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/27 10:38:59 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	bg_noise(t_game *game)
{
	int	x;
	int	y;
	int	col;

	x = -1;
	y = -1;
	while (y <= SCREEN_HEIGHT)
	{
		if (++x >= SCREEN_WIDTH && ++y > -2)
			x = 0;
		if (random() * 1 > RAND_MAX / 1.15)
		{
			if (y <= game->horizont + game->player.jump_offset)
				col = get_grad_col(
						y, game->horizont + game->player.jump_offset,
						C_NEON_VIOLET, 0x0); 
			else
				col = get_grad_col(
						game->horizont + game->player.jump_offset, y,
						C_NEON_YELLOW, 0x0); 
			pixel_put(&game->img, x, y, col);
		}
	}
}

void	red_noise(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (y <= SCREEN_HEIGHT)
	{
		if (++x >= SCREEN_WIDTH && ++y > -2)
			x = 0;
		if (random() * 1 > RAND_MAX / 1.7)
			pixel_put(&game->img, x, y, C_RED);
	}
	game->player.wall_hit--;
	if (game->player.wall_hit < 0)
		game->player.wall_hit = 0;
}
