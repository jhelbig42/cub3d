/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:35:01 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/07 10:05:13 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_wall_x(t_game *game, int x, int wall_height)
{
	int	y;
	int	top;

	y = game->horizont - wall_height / 2.0f + game->player.jump_offset;
	top = game->horizont + wall_height / 2.0f + game->player.jump_offset;
	while (y++ < top)
		pixel_put(&game->img, x + 1, y, C_NEON_BLUE);
}
